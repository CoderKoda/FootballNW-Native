# FootballNW Native

A native C++ football simulation for the NumWorks N0120, built with the EADK.

This repository is the native rewrite of the original Python FootballNW project. The Python version remains the reference implementation; this repository targets the calculator directly.

## Current status

The project currently contains a lightweight application shell:

- FootballNW home screen
- Keyboard navigation with Up, Down, OK and Back
- Placeholder pages for New Match, Teams, Match History and Settings
- NumWorks NWA build configuration

The football simulation engine has not been ported yet. The next development stages are the team/player data model, match state, event system and simulation engine.

## Requirements

On macOS with Homebrew:

```sh
brew install numworks/tap/arm-none-eabi-gcc node
```

You also need Git and a USB connection to the calculator for direct installation.

## Build

From the repository root:

```sh
make
```

The build produces:

- `target/footballnw.nwa` — installable NumWorks application
- `target/footballnw.bin` — binary generated from the NWA

The Makefile pins `nwlink@0.0.19` and uses the device EADK compiler flags.

## Install on a connected calculator

Connect the NumWorks calculator over USB, then run:

```sh
make run
```

Alternatively, upload `target/footballnw.nwa` using the NumWorks application uploader.

## Project layout

```text
src/
├── main.cpp
├── eadkpp.h
├── icon.png
└── ui/
    ├── home_screen.cpp
    └── home_screen.h
```

As the simulator grows, its code will be separated into small modules. The target is the N0120's limited resources, so data structures and runtime allocations will be kept bounded and measured on-device.

## License

See [LICENSE](LICENSE) for the original sample project's BSD license and attribution.
