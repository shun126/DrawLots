# Contributing to DrawLots

Thank you for your interest in contributing to DrawLots.

DrawLots is a small Unreal Engine plugin focused on weighted random selection.
The goal of the project is to stay simple, practical, and easy to use from both Blueprint and C++.

---

## Ways to Contribute

You can contribute in several ways:

- Report bugs
- Suggest improvements
- Improve documentation
- Add Blueprint examples
- Add C++ examples
- Improve code readability
- Fix compatibility issues
- Help verify behavior on different Unreal Engine versions or platforms

Small contributions are welcome.

---

## Before You Start

Before making a large change, please open an Issue or Discussion first.

This helps avoid duplicated work and makes sure the proposed change fits the direction of the plugin.

Good topics to discuss first:

- New public API
- Behavior changes
- Breaking changes
- Large refactoring
- Platform-specific changes
- Changes to probability behavior
- Changes that affect Blueprint compatibility

---

## Project Direction

DrawLots should remain:

- Lightweight
- Easy to understand
- Blueprint-friendly
- C++ friendly
- Focused on weighted random selection
- Safe to use in game runtime code

Please avoid adding unrelated systems or large framework-style features.

This plugin should solve one problem well:
**selecting a weighted random result in Unreal Engine.**

---

## Reporting Bugs

When reporting a bug, please include:

- Unreal Engine version
- Plugin version or commit hash
- Operating system
- Target platform
- Whether the issue happens in Blueprint, C++, or both
- Steps to reproduce
- Expected behavior
- Actual behavior
- Screenshots, logs, or sample data if possible

A good bug report makes the issue much easier to fix.

---

## Suggesting Features

Feature requests are welcome, but please keep the scope of the plugin in mind.

Good feature requests:

- Improve weighted selection usability
- Improve Blueprint workflow
- Add useful examples
- Improve error handling
- Improve documentation
- Improve compatibility with Unreal Engine versions

Features may be declined if they make the plugin too complex or move it away from its main purpose.

---

## Pull Request Guidelines

Before opening a pull request:

1. Fork the repository.
2. Create a feature branch.
3. Make your changes.
4. Test the plugin in Unreal Engine.
5. Update documentation if needed.
6. Open a pull request with a clear description.

Example branch names:

```txt
fix/invalid-lottery-result
docs/add-blueprint-example
feature/add-sample-usage
````

---

## Pull Request Description

Please include the following in your pull request description:

```md
## Summary

Briefly explain what this pull request changes.

## Motivation

Explain why this change is useful.

## Changes

- Change 1
- Change 2
- Change 3

## Testing

Describe how you tested the change.

## Notes

Add anything reviewers should know.
```

---

## Coding Guidelines

Please follow the existing Unreal Engine C++ style as much as possible.

General guidelines:

* Keep code simple and readable.
* Prefer clear names over clever code.
* Avoid unnecessary dependencies.
* Avoid large unrelated refactoring.
* Keep Blueprint compatibility in mind.
* Do not change existing public behavior without explaining why.
* Add comments only when they clarify intent or important behavior.

---

## Blueprint Compatibility

DrawLots is intended to be easy to use from Blueprint.

When changing USTRUCT, UPROPERTY, or UFUNCTION declarations, please be careful about:

* Existing Blueprint assets
* Property names
* Function names
* Default values
* Return values
* Category names
* Serialization compatibility

Breaking Blueprint compatibility should be avoided unless there is a strong reason.

---

## Return Value Rules

Please preserve the current failure behavior unless there is a clear reason to change it.

Current behavior:

* `DrawLotsIndex` returns `-1` when a draw cannot be performed.
* `DrawLotsObject` returns `nullptr` when a draw cannot be performed.

If you propose changing these rules, please discuss it in an Issue first.

---

## Documentation Contributions

Documentation improvements are very welcome.

Useful documentation contributions include:

* Better README explanations
* Blueprint screenshots
* Step-by-step examples
* C++ examples
* Common use cases
* Troubleshooting notes
* Unreal Engine version notes

Please keep documentation clear and practical.

---

## Testing

When possible, test changes in an Unreal Engine project.

Recommended checks:

* Plugin can be enabled successfully.
* Project compiles.
* Blueprint nodes are available.
* `DrawLotsIndex` returns valid indices.
* `DrawLotsObject` returns valid objects.
* Invalid or empty lottery data fails safely.
* Consecutive duplicate control behaves as expected.
* Existing Blueprint usage is not broken.

If you cannot test a specific environment, mention that in the pull request.

---

## Commit Messages

Please use clear commit messages.

Good examples:

```txt
Fix invalid result when lottery data is empty
Add Blueprint usage example to README
Improve DrawLotsObject documentation
```

Avoid vague messages such as:

```txt
Update files
Fix stuff
WIP
```

---

## License

By contributing to this repository, you agree that your contributions will be licensed under the MIT License.

---

## Support the Project

The GitHub version and the Fab version contain the same plugin.

If this plugin helps your project, please consider starring the repository or supporting the project through Fab or [![ko-fi](https://ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/M4M413XDXB).
