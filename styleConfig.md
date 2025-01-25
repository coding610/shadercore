# StyleConfig

## Structure
- Every Engine/Module should have a crate attatched.
- Every Engine/Module should have a update method.
- Every file should have a overview comment description.
  In this comment description the name and the parent
  should also be added "-- Name of Parent --".
- Engines should interact with each other by passing
  theirselfs as references in params in update function.
- Modules should have no interaction between each other at all,
  and should be saved privatly in the engine.
- Modules should not be accessed by other engines.

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
- Paths should always be absolute
- Public over private
- Methods over variables

## Habits
- Use const and references whenever possible.
- All the engines/modules and descriptions should be added to excalidraw.
- Use pragma once
