# DrawLots

[![Unreal Engine](https://img.shields.io/badge/Unreal%20Engine-Plugin-313131?logo=unrealengine)](https://www.unrealengine.com/)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![GitHub release](https://img.shields.io/github/v/release/shun126/DrawLots)](https://github.com/shun126/DrawLots/releases)
[![GitHub stars](https://img.shields.io/github/stars/shun126/DrawLots?style=social)](https://github.com/shun126/DrawLots/stargazers)

**DrawLots** is a lightweight Unreal Engine plugin for weighted random selection.

It lets you define lottery entries with individual weights and draw a result from Blueprint or C++.
Use it for item drops, enemy spawn selection, random rewards, gacha-like systems, procedural events, dialogue variation, and any other game logic that needs simple weighted probability.

---

## Features

- Weighted random selection for Unreal Engine
- Blueprint-friendly data structures and functions
- Select by index or by object reference
- Optional prevention of consecutive duplicate results
- Returns safe fallback values when a draw cannot be performed
- Small, focused runtime plugin
- MIT licensed open-source project

---

## Why use DrawLots?

Many games need weighted random selection.

For example:

| Item | Weight |
|------|--------|
| Common Potion | 70 |
| Rare Gem | 20 |
| Legendary Sword | 1 |

You could write this logic manually every time, but it quickly becomes repetitive.

DrawLots provides reusable lottery data types and Blueprint-callable functions so you can define probabilities in the editor and draw results with a simple node.

---

## Open Source and Fab Version

The GitHub version and the Fab version contain the same plugin.

The Fab version is provided as a convenient way to support the project.
If DrawLots is useful for your project and you would like to support continued maintenance, purchasing it on Fab is greatly appreciated.

- GitHub: source code, issues, pull requests, releases
- Fab: same plugin, convenient installation and project support

---

## Installation

### Option 1: Install from GitHub

1. Download or clone this repository.
2. Copy the `DrawLots` folder into your Unreal Engine project's `Plugins` directory.

Example:

```txt
YourProject/
  Plugins/
    DrawLots/
      DrawLots.uplugin
````

3. Regenerate project files if necessary.
4. Open your project in Unreal Engine.
5. Enable the plugin from **Edit > Plugins** if it is not already enabled.
6. Restart the editor.

### Option 2: Install from Fab

Install the plugin from Fab and enable it in your Unreal Engine project.

Purchasing the Fab version is also a way to support the project.

---

## Basic Concepts

DrawLots provides two main lottery data types.

### FDrawLotsIndex

Use `FDrawLotsIndex` when you only need the selected array index.

This is useful when your actual data already exists elsewhere, such as an array of enemy classes, item IDs, data table rows, or custom structs.

```txt
Odds = [70, 20, 10]
```

A draw returns:

```txt
0, 1, or 2
```

The probability of each index is based on its weight.

### FDrawLotsObject

Use `FDrawLotsObject` when you want to assign an object directly to each lottery entry.

Each entry has:

* `Odds`
* `Item`

A draw returns the selected object.

---

## Blueprint Usage

### Draw by Index

1. Add a variable of type `DrawLotsIndex`.
2. Add weights to the `Odds` array.
3. Call `DrawLotsIndex`.
4. Use the returned index.

Return value:

* Returns the selected array index.
* Returns `-1` if the draw cannot be performed.

A draw cannot be performed when there are no valid entries or all weights are invalid for selection.

### Draw by Object

1. Add a variable of type `DrawLotsObject`.
2. Add lottery entries.
3. Set `Odds` for each entry.
4. Set `Item` for each entry.
5. Call `DrawLotsObject`.

Return value:

* Returns the selected object.
* Returns `nullptr` if the draw cannot be performed.

---

## Consecutive Duplicate Control

Both draw functions have a `consecutive` option.

When `consecutive` is enabled, the same result may be selected repeatedly.

When `consecutive` is disabled, DrawLots tries to avoid selecting the same result twice in a row.

This is useful for cases such as:

* Avoiding the same enemy spawn twice in a row
* Preventing repeated dialogue lines
* Making random rewards feel less repetitive
* Improving perceived randomness for players

---

## Example Use Cases

### Item Drops

Use DrawLots to select reward items based on rarity.

```txt
Common Item     : 80
Rare Item       : 15
Legendary Item  : 5
```

### Enemy Spawns

Use different weights depending on area, dungeon depth, difficulty, or game progress.

```txt
Slime       : 60
Goblin      : 30
Minotaur    : 10
```

### Random Events

Use weighted selection to choose procedural events.

```txt
Nothing happens : 50
Treasure room   : 20
Enemy ambush    : 20
Secret event    : 10
```

### Dialogue Variation

Disable consecutive results to avoid playing the same line repeatedly.

---

## C++ Usage

DrawLots can also be used from C++.

```cpp
FDrawLotsIndex DrawLots;
DrawLots.Odds = { 70, 20, 10 };

const int32 ResultIndex = UDrawLotsBlueprint::DrawLotsIndex(DrawLots, true);

if (ResultIndex >= 0)
{
    // Use selected index
}
```

Object lottery example:

```cpp
FDrawLotsObject DrawLots;

// Add FLotteryItem entries to DrawLots.LotteryItems.
// Each entry contains Odds and Item.

UObject* ResultObject = UDrawLotsBlueprint::DrawLotsObject(DrawLots, true);

if (ResultObject != nullptr)
{
    // Use selected object
}
```

---

## API Overview

### FDrawLotsIndex

Weighted lottery data that returns a selected index.

| Property | Description              |
| -------- | ------------------------ |
| `Odds`   | Array of lottery weights |

### FDrawLotsObject

Weighted lottery data that returns a selected object.

| Property       | Description              |
| -------------- | ------------------------ |
| `LotteryItems` | Array of lottery entries |

### FLotteryItem

Lottery entry used by `FDrawLotsObject`.

| Property | Description                                 |
| -------- | ------------------------------------------- |
| `Odds`   | Weight of this entry                        |
| `Item`   | Object returned when this entry is selected |

### Blueprint Functions

| Function         | Description                                                  |
| ---------------- | ------------------------------------------------------------ |
| `DrawLotsIndex`  | Draws from `FDrawLotsIndex` and returns the selected index   |
| `DrawLotsObject` | Draws from `FDrawLotsObject` and returns the selected object |

---

## Return Values

| Function         | Success         | Failure   |
| ---------------- | --------------- | --------- |
| `DrawLotsIndex`  | Selected index  | `-1`      |
| `DrawLotsObject` | Selected object | `nullptr` |

Always check the return value when the lottery data may be empty or invalid.

---

## Supported Platforms

The plugin is designed as a lightweight runtime plugin for Unreal Engine projects.

Current platform settings are defined in `DrawLots.uplugin`.

---

## Documentation

Additional documentation may be added to the GitHub Wiki:

* Usage examples
* Blueprint screenshots
* C++ examples
* Advanced probability setup
* Common patterns for game systems

---

## Support

For questions, ideas, or bug reports, please use:

* GitHub Issues for bugs and feature requests
* GitHub Discussions for general questions and support

When reporting a bug, please include:

* Unreal Engine version
* Plugin version
* Platform
* Steps to reproduce
* Expected result
* Actual result
* Screenshots or logs if available

---

## Contributing

Contributions are welcome.

Please read [CONTRIBUTING.md](CONTRIBUTING.md) before opening a pull request.

Good contribution examples:

* Bug fixes
* Documentation improvements
* Blueprint usage examples
* C++ usage examples
* Test projects or sample scenes
* Improvements that keep the plugin simple and focused

---

## License

DrawLots is released under the MIT License.

See [LICENSE](LICENSE) for details.

---

If this plugin helps your project, please consider starring the repository or supporting the project through Fab or [![ko-fi](https://ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/M4M413XDXB).
