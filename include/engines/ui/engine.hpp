/*
-- UiEngine of App --

- Manages ImGUI initialization and logic.
- Provides all of the expected user controls,
  like changing colors and positions.

*/

#pragma once


struct UiCrate { };

class UiEngine {
public:
    UiEngine(const UiCrate& crate);
    ~UiEngine();

    void update();

private:
};
