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
/*
		Description
	So, thi is all about c++ casts. C++ casts are no different from C-casts, do
 		the same thing, but provide some benefits:
 		- They are "searchable". Meaning - if you want to find a casts in your
 			project - you can search for ".._cast<...". Try to do it with
 			C-style (...) cast.
		- They provide some communication functionality. Some can throw
			errors or exceptions, or return NULL - if cast is not possible.
		- They have self-explaining names, to make code more understandable.
	There are 4 basic kinds of casting:
 		1. Static Cast
		2. Dynamic Cast
		3. Const Cast
		4. Reinterpret Cast

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

	Static Polymorphism

	It is a same thing, but reversed. Instead of adding functionality to the
 Derived class we do it in Base. There is a mechanic, tha allows us to add
 functionality to the Derived class from inside the Base. It is called CRTP -
 Curiously Recurrent Template Pattern.
 	Let's say we have a class Duck, that has a quack() method, that makes a Duck
quack. But we want to add something to this method, without modifying it's
code, and without copying code that we want to leave as it is. Let's make our
duck introduce it's name, before making a quack().
 	1. Lets make for a Duck a parent class QuackerActions that will add some
functionality, with a template, assuming, that it will be a Duck.
 	2. Inherit Duck from QuackerActions passing <Duck> as a template.
 	3. Add 2 overloaded methods, that will make Duck introduce itself and
another Quacking one given as argument.
 	4. Inside method we can SAFELY DOWNCAST parent class using
static_cast<template's Name&>(*this or arg) to the template's name class - which
is should be a class, that has a std::string name_ and quack() method.
 	5. We can do with this Template's instance whatewer we can do with a Duck.
If we'll try to, let's say, call a method that duck doesn't have - it will be
 a compile-time error, that we'll see instantly.

 	Here is how it looks like:

  template <typename Quacking>
struct QuackerActions {
//	Quacking one introduces itself
	void QuackingMakesQuack() {
		Quacking quacking = static_cast<const Quacking&>(*this);
		std::cout << "My name is : " << quacking.name_ << std::endl;
		quacking.quack();
	}
//	Quacking one introduces another Quacking one
	void QuackingMakesQuack(const QuackerActions &quacking_one) {
		Quacking quacking = static_cast<const Quacking&>(quacking_one);
		std::cout << "Duck's name is : " << quacking.name_ << std::endl;
		quacking.quack();
	}
};

struct Duck : QuackerActions<Duck>{
	std::string name_;

	explicit Duck(const std::string &name) : name_(name) {}

	void quack() {
		std::cout << "Quack!" << std::endl;
	}
};

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
 	This weird structure, where class kind of inherits itself comes with some
benefits:
 - It is faster. Cause it all gets resolved during compilation, when all dynamic
 stuff - during runtime.
 - It is great for code reuse. For example - you can create a Base class that
 has all equality operators defined on the basis of operator<, and then in
 all Derived classes instead of defining them all multiple times you can only
 define operator< and inherit everything else from Base.

 		And finally - casts:

 	static_cast < new-type > ( expression )

	If new-type is a reference to some class D and expression is a lvalue of
its non-virtual base B (1), or new-type is a pointer to some complete class D
 and expression is a prvalue pointer to its non-virtual base B, static_cast
 performs a downcast. (This downcast is ill-formed if B is ambiguous,
 inaccessible, or virtual base (or a base of a virtual base) of D.)
	Such a downcast makes no runtime checks to ensure that the object's runtime
type is actually D, and may only be used safely if this precondition is
guaranteed by other means, such as when implementing STATIC POLYMORPHISM. Safe
downcast may be done with dynamic_cast. If the object expression refers or points
to is actually a base class subobject of an object of type D, the result refers
to the enclosing object of type D. Otherwise, the behavior is undefined.

 	struct B {};
	struct D : B { B b; };

	D d;
	B& br1 = d;
	B& br2 = d.b;

(1) static_cast<D&>(br1); // OK: lvalue denoting the original d object
(2) static_cast<D&>(br2); // UB: the b subobject is not a base class subobject

Used:

  - If there is an implicit conversion sequence from expression to new-type, or
 if overload resolution for a direct initialization of an object or reference of
 type new-type from expression would find at least one viable function, then
 static_cast<new-type>(expression) returns the imaginary variable Temp
 initialized as if by new-type Temp(expression);, which may involve implicit
 conversions, a call to the constructor of new-type or a call to a user-defined
 conversion operator.
  - If new-type is the type void (possibly cv-qualified), static_cast discards
 the value of expression after evaluating it.
  - If a standard conversion sequence from new-type to the type of expression
 exists, that does not include lvalue-to-rvalue, array-to-pointer,
 function-to-pointer, null pointer, null member pointer, or boolean conversion,
 then static_cast can perform the inverse of that implicit conversion.
  - If conversion of expression to new-type involves lvalue-to-rvalue,
 array-to-pointer, or function-to-pointer conversion, it can be performed
 explicitly by static_cast.

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