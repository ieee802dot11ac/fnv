# Getting Started

See [Dependencies](dependencies.md) first.

1. [Create a new repository from this template](https://github.com/new?template_name=jeff-template&template_owner=rjkiv), then clone it.

2. Rename `orig/GAMEID` to the game's ID. (For example, `373307D9` for _Dance Central 3_.)

3. Place your game's XEX in `orig/[GAMEID]`. If you have a `.map` file, place it here too.

4. Rename `config/GAMEID` to the game's ID and modify `config/[GAMEID]/config.yml` appropriately, using [`config.example.yml`](/config/GAMEID/config.example.yml) as a reference. If the game doesn't use RELs, the `modules` list in `config.yml` can be removed.

5. Update `VERSIONS` in [`tools/defines_common.py`](../tools/defines_common.py) with the game ID.

6. Run `python configure.py` to generate the initial `build.ninja`.

7. Run `ninja` to perform initial analysis.

If all goes well, the initial `symbols.txt` and `splits.txt` should be automatically generated. Though it's likely it won't build yet. See [Post-analysis](#post-analysis) for next steps.

## Using a `.map`

If the game has `.map` files matching the DOL (and RELs, if applicable), they can be used to fill out `symbols.txt` and `splits.txt` automatically during the initial analysis.

Add the `map` key to `config.yml`, pointing to the `.map` file from the game disc. (For example, `orig/[GAMEID]/files/main.map`.) For RELs, add a `map` key to each module in `config.yml`.

Once the initial analysis is completed, `symbols.txt` and `splits.txt` will be generated from the map information. **Remove** the `map` fields from `config.yml` to avoid conflicts.

## Post-analysis

After the initial analysis, `symbols.txt` and `splits.txt` will be generated. These files can be modified to adjust symbols and split points.
