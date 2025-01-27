# StyleConfig

## Structure
- Every file using either one of a opengl dependency should include all in the order below:
    - glew
    - glfw3
    - gl
- Modules are more flexible than engines in design.
- Every Engine should have a crate attatched to the INIT method.
  The builder should be default.
- Every Engine/Module should have a update method.
- Every file should have a overview comment description.
  In this comment description the name and the parent
  should also be added "-- Name of Parent --".
- Engines should interact with each other by passing
  theirselfs as references in params in update function.
- Modules should have no interaction between each other at all,
  and should be saved privatly in the engine.
- Modules should not be accessed by other engines.
- Every engine/module should have a init, that will be seperatly
  called from the constructor. The init will handle creating of
  private members, and the constructor initializes the create info.

## Naming
### Code
PascalCase for every class/struct.
- []Engine
- []Module
- []Crate

camelCase for every class member/method.
- void myMethod();
- int myMember;

### Files
- Files should be in camelCase.
- Directory structure should be like below

```
* include
    * engines
        * \[Engine Name\]
            * engine.hpp
            * \[Potiential module names\].cpp

* src
    * engines
        * \[Engine Name\]
            * engine.cpp
            * \[Potiential module names\].cpp
```


### Hierarchy
1. Engine
2. Module

## Style
- Paths should always be absolute (to own hpp)
- Public over private
- Methods over variables
- Long functions is prefered. Seperating functions into many is a possibility, but use it carefully.
- Comment seperators is in the form of "////// \[\[speration\]\] //////"
- Include order:
    - std libs
    - opengl
    - glfw
    - vmml
    - own includes

## Habits
- Use const and references whenever possible.
- All the engines/modules and descriptions should be added to excalidraw.
- Avoid static
- Use pragma once
