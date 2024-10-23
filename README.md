# DrawLots

[![Unreal Engine Supported Versions](https://img.shields.io/badge/Unreal_Engine-5.1~5.4-9455CE?logo=unrealengine)](https://www.unrealengine.com/)
[![license](https://img.shields.io/github/license/shun126/DrawLots)](https://github.com/shun126/DrawLots/blob/main/LICENSE)
[![release](https://img.shields.io/github/v/release/shun126/DrawLots)](https://github.com/shun126/DrawLots/releases)
[![downloads](https://img.shields.io/github/downloads/shun126/DrawLots/total)](https://github.com/shun126/DrawLots/releases)
[![stars](https://img.shields.io/github/stars/shun126/DungeonGenerator?style=social)](https://github.com/shun126/DrawLots/stargazers)

Lottery plugin to specify winning weight for Unreal Engine

Have you ever had trouble processing a lottery?
This plugin allows you to draw lots according to the probability of winning.

# Table of Contents
* Prepare Lottery Data
  * Preparing the lottery data as an index
  * Preparing the lottery data as an object
* Draw lots !

# Prepare the lottery data
First, prepare the lottery data in variables.
`DrawLotsIndex` to register only the probability of winning and get the index. There are two types of lottery data: `DrawLotsObject`, which registers the probability of winning and an object to draw the lottery.

## Prepare by index
1. Add `DrawLotsIndex` to the variable.
1. Compile.
1. Add the required number of winning items to `DrawLotsIndex` of `Details`.
1. set the probability of winning.

![DrawLotsIndex](https://github.com/shun126/DrawLots/assets/23472415/8c21e707-c652-4989-bf58-cf58614f73a9)

## Prepare the object as an object
1. Add `DrawLotsObject` to the variable
1. Compile.
1. Add the required number of winning items to `DrawLotsObject` in `Details`.
1. Set the probability of winning.
1. Set the winning items.

![DrawLotsObject](https://github.com/shun126/DrawLots/assets/23472415/4c23578f-1569-4c35-a20d-965a7d2819e4)

# Draw lots !
![DrawLots-BP](https://github.com/shun126/DrawLots/assets/23472415/df31ac0b-e5f6-46d6-be8c-17afba08ef98)

1. create a node referring to Blueprint
1. use function `DrawLotsIndex` to draw the variable `DrawLotsIndex`
   1. return the winning array number
   1. return `-1` if the lottery cannot be drawn, e.g. if you set all probabilities to 0
   1. disable `consecutive` to prevent the same number from being drawn consecutively 1. use the variable `DrawLotsIndex`
1. use function `DrawLotsObject` to draw the variable `DrawLotsObject`
   1. return the winning item
   1. return `nullptr` if the item cannot be drawn, e.g. if you set all probabilities to 0
   1. if consecutive is disabled, the same item will not be drawn consecutively

# 👾 Authors
* [Nonbiri](https://www.youtube.com/channel/UCkLXe57GpUyaOoj2ycREU1Q)
* [Shun Moriya](https://x.com/moriya_zx25r)

[![ko-fi](https://ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/M4M413XDXB)
