/******************************************************************************/
/*                                                                            */
/*                                                         :::      ::::::::  */
/*    main.cpp                                           :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*    By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*    Created: 2023/02/04 15:56:06 by rokupin           #+#    #+#            */
/*                                                     ###   ########.fr      */
/*                                                                            */
/******************************************************************************/
/**
		Description
	So, this is all about c++ casts. C++ casts are no different from C-casts, do
 		the same thing, but provide some benefits:
 		- They are "searchable". Meaning - if you want to find a casts in your
 			project - you can search for ".._cast<...". Try to do it with
 			C-style (...) cast.
		- They provide some communication functionality. Some can throw
			errors or exceptions, or return NULL - if cast is not possible.
		- They have self-explaining names, to make code more understandable.
		- They are designed to disambiguate cast operations dealing with
			polymorphism because C++ adds the following features that really
			change the game:
    			+ Inheritance
    			+ Templates
	In C ++ there are three different things we might mean by a pointer cast.
 	Say class D derives from class B, and we declare a pointer B* pb;
 	What should (D*)pb do? Here are three possibilities:

    	1. Return a pointer to the same byte of memory, but just change the type
    	of the pointer. (This is the same as what all pointer casts do in C)
    	2. Check whether the B* really points to a B that is part of a D object.
    	If so, return a pointer to the D object. If not, fail (maybe by
    	returning a null pointer or throwing an exception.)
    	3. Assume that the B* points to a B that is part of a D object;
    	don't bother performing a check. Adjust the address of the pointer if
    	necessary so that it will point to the D object.

	It is conceivable that in C++ we might want to perform any of these three
 	conversions. Therefore, C++ gives us three different casts:
 	reinterpret_cast<D*> for function (1),
 	dynamic_cast<D*> for function (2),
 	and static_cast<D*> for function (3).

    dynamic_cast casts up and down class hierarchies only, always checking that
    	the conversion requested is valid.
    static_cast performs implicit conversions, the reverses of implicit standard
    	conversions, and (possibly unsafe) base to derived conversions.
    reinterpret_cast converts one pointer to another without changing the
    	address, or converts between pointers and their numerical values.
    const_cast only changes cv-qualification; all other casts cannot cast away
    	constness.

		And the reason why there are four different casts in C++ is so that you
 	can write a cast and be explicit about what kind of conversion you intend to
 	perform; the compiler will never incorrectly "guess" what you meant; and
 	other people reading your code will be able to tell what kind of conversions
 	it does.

 	Let's start with a first two. To fully understand that we need to make a
	step back and recall a polymorphism. Dynamic and static one.

 	Dynamic Polymorphism

	Here are the key facts. Dynamic Polymorphism takes place at run time, it is
based on object orientation and enables us to separate between the interface and
the implementation of a class hierarchy. To get late binding, dynamic dispatch,
or dispatch at run time, you need two ingredients: virtuality and an
indirection such as a pointer or a reference.
 	In other words - when we declare a reference or pointer of a base-class type
and assign it to the derived-class object - we have a base-classes interface
 and derived-class implementation.
 The static (left) type is used at compile time and the dynamic (right) type at
 run time.

				Static type					Dynamic type
          ┌───────────────────────┐    ┌────────────────────────┐
          │          class Bird   │    │   class Duck : Bird    │
┌─────────┼─────────────────────┐ │    │                        │
│Interface│ virtual  void Fly();│─┼─┐  │   void Fly() override; │
└─────┬───┼─────────────────────┘ │ │  │   void Quack();        │
      │   │                       │ │  │ ┌──────────────────────┼──────────────┐
      │   │         void Fly() {  │ │  │ │ void Fly() {         │              │
      │   │            flying;    │ │  │ │    flying as a duck; │Implementation│
      │   │         }             │ └──┼─│ }                    │              │
      │   └───────────────────────┘    │ └──────────────────────┼────────┬─────┘
      │                                │   void Quack() {       │        │
      │                                │     QUACK!             │        │
      │                                │   }                    │        │
      │                                └────────────────────────┘        │
      │                                                                  │
      │                                                                  │
      │            ┌───────────────────────────┐                         │
      └───────────►│Bird* quackie = new Duck();│◄────────────────────────┘
                   └───────────────────────────┘
In general, there's nothing wrong to do so in the first place, but in a C++
context there are some comments here.
	First, since we use virtual functions we create a vtable and during runtime
 we call the apropriate function. There are benchmarks and articles which show
 that this has impact on the application's performance.
	Second, do we really need to take the concrete implementation during runtime?
 It's more often the case that we already know during compile
 time which one we need. We often confused why we use something dynamic
 when we  don't need it dynamic.

	Static Polymorphism

	Let's move the implementation from above to a static one.
 CRTP (Curiously recurring template pattern) is a method which can be seen as
 static polymorphism (note, there are other advantages to use CRTP it's not that
 CRTP is static polymorphism).
 	Let's say we have a class Duck, that has a quack() method, that makes a Duck
quack. But we want to add something to this method, without modifying its
code, and without copying code that we want to leave as it is. Let's make our
duck introduce its name, before making a quack().
 	1. Let's make for a Duck a parent class QuackerActions that will add some
functionality, with a template, assuming, that it will be a Duck.
 	2. Inherit Duck from QuackerActions passing <Duck> as a template.
 	3. Add 2 overloaded methods, that will make Duck introduce itself and
another Quacking one given as argument.
 	4. Inside method, we can SAFELY DOWNCAST parent class using
static_cast<template's Name&>(*this or arg) to the template's name class - which
should be a class, that has a std::string name_ and quack() method.
 	5. We can do with this Template's instance whatever we can do with a Duck.
If we'll try to, let's say, call a method that duck doesn't have - it will be
 a compile-time error, that we'll see instantly.

 	Here is how it looks like:
// now we have a templated base class
template <typename Quacking>
struct QuackerActions {
// no virtual function here
	void QuackingMakesQuack() {
// and we cast this to the template type, where the actual implementation lives
		Quacking quacking = static_cast<const Quacking&>(*this);
		std::cout << "My name is : " << quacking.name_ << std::endl;
		quacking.quack();
	}
	void QuackingMakesQuack(const QuackerActions &quacking_one) {
// Well, not necesserely this
		Quacking quacking = static_cast<const Quacking&>(quacking_one);
		std::cout << "Duck's name is : " << quacking.name_ << std::endl;
		quacking.quack();
	}
};
// our class derived inherits from base and passes itself as template parameter
struct Duck : QuackerActions<Duck>{
	std::string name_;

	explicit Duck(const std::string &name) : name_(name) {}

	void quack() {
		std::cout << "Quack!" << std::endl;
	}
};
// another one
struct RubberDuck : QuackerActions<RubberDuck>{
	std::string name_;

	explicit RubberDuck() : name_("Made in China.") {}

	void quack() {
		std::cout << "Squeak!" << std::endl;
	}
};

 int main() {

	Duck duck1 = Duck("Ducky boiii");
	Duck duck2 = Duck("Quacky-Ducky");
	RubberDuck duck3 = RubberDuck();

	duck1.QuackingMakesQuack();
	duck1.QuackingMakesQuack(duck2);
	duck3.QuackingMakesQuack();
 	return 0;
 }
 Output:
┌───────────────────────────────┐
│ My name is : Ducky boiii      │
│ Quack!                        │
│ Duck's name is : Quacky-Ducky │
│ Quack!                        │
│ My name is : Made in China.   │
│ Squeak!                       │
└───────────────────────────────┘
  	We'll make sure that base is used that way and therefore with
 static_cast<Quacking*>(*this) we have access to the actual concrete implementation.
 Now we have a static approach of an interface.
 	This weird structure, where class kind of inherits itself comes with some
benefits:
 - It is faster. Cause it all gets resolved during compilation, when all dynamic
 stuff - during runtime.
 - It is great for code reuse. For example - you can create a Base class that
 has all equality operators defined on the basis of operator<, and then in
 all Derived classes instead of defining them all multiple times you can only
 define operator< and inherit everything else from Base.

 */
#include <cassert>
#include <iostream>
#include "ScalarConversion.h"

int main(int ac, const char** av) {
	assert(ac == 2 && "There should be only 1 argument");
	try {
		ScalarConversion val(av[1]);
		std::cout << val << std::endl;
	} catch (const ScalarConversion::WrongInputException& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}