# DWEngine

This is a simple 2D-platformer game engine built on top of SDL2 built to experiment with and learn about common architectures in modern game engines. The engine features an ECS architecture with JSON configuration and lua scripting for NPC control.

## Dependencies

Dependencies are as follows:

- SDL2 @ V2.32.2
- SDL2-ttf @ V2.24.0
- SDL2-mixer @ V2.8.1
- SDL2-image @ V2.8.8
- Lua @ V5.4.6
- libavif @ V1.1.1
- nlohmann-json @ V3.11.3
- Sol2 (provided in `external` directory)

## Data structure

The assets for the game are defined within the `assets/assets.json` file. This file describes each asset to be used by the engine with IDs associated with each. The assets are defined in objects of the form:

```json
{
  "id": "<asset ID>",
  "type": "<asset type identifier>",
  "path": "<path to asset file>",
  "data": {}
}
```

`data` here is an object with structure specific to the asset type, e.g. for asset type `ASSET_SPRITE_SHEET`, the following can be used:
```json
{
  "rows": <number of rows in the sheet>,
  "columns": <number of columns in the sheet>,
  "animations": [
    {
      "id": "<ID of the animation>",
      "from": <cell number in the sprite sheet to start the animation>,
      "to": <cell number in the sprite sheet to end the animation>,
    }, ...
  ]
}
```
For sprite sheet animations, the cells start at 0 in the top left and count up to the right and then down. Animations are assumed to store frames in sequence following this order.


The accompanying `assets/entities.json` file describes each entity within the game. Components associated to those entities are defined within the `component` object of the JSON describing each entity. Assets can be referenced by the IDs as defined above.

```json
{
  "id": "<ID of the entity>",
  "type": "<entity type identifier>",
  "tags": <array of tags applied to the entity>,
  "components": [
    "PositionComponent": { ... },
    ...
  ]
}
```

Components each can have different data defined in their associated objects. See the definitions under `DWEngine/ecs/components` for details of each of these. 

The `config/config.json` file stores the configuration of the engine, including audio volume and window resolution.
