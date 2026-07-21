# Minecraft Compass — Digital Build

This repo documents my journey building a digital compass inspired by Minecraft, using an LED matrix PCB inside a custom 3D-printed enclosure.

## Preview

### FreeCAD design
<img width="2560" height="1600" alt="compass-1" src="Images\Preview\compass-1.jpg" />
<img width="2560" height="1600" alt="bottom-0" src="Images\Preview\bottom-0.png" />
<img width="2560" height="1600" alt="bottom-1" src="Images\Preview\bottom-1.jpg" />
<img width="2560" height="1600" alt="top-0" src="Images\Preview\top-0.png" />

### KiCAD design
<img width="2560" height="1600" alt="LED_matrix_front" src="Images\Preview\LED_matrix_front.png" />
<img width="2560" height="1600" alt="LED_matrix_back" src="Images\Preview\LED_matrix_back" />
<img width="2560" height="1600" alt="daughter_board" src="Images\Preview\daughter_board" />


## Repository Structure

| Path | Contents |
|---|---|
| `STL/` | 3D-printable enclosure files. Subdirectories (`ver1`–`ver9`) track design iterations; the latest is in `STL/ver9/`. |
| `KiCAD/Clone-new_ledMatrix/` | Current KiCAD PCB project (schematic, layout, and Gerber exports). |
| `KiCAD/new_ledMatrix/` | Earlier KiCAD project kept for reference. |
| `FreeCAD/` | FreeCAD source models for the enclosure. |
| `PCB/` | Fabrication-ready Gerber ZIP files for ordering the PCB. |
| `test_code/` | Firmware and animation test sketches. |
| `datasheets/` | Component datasheets (e.g. WS2812B-MINI LED). |
| `images/` | Project screenshots and reference images. |

## 3D Printing the Enclosure

The current STL files are in [`STL/ver9/`](STL/ver9/). Import them into your slicer (e.g. PrusaSlicer or Cura) and print as-is — no supports should be required.

## Prior Design Iterations

All previous versions of every file are preserved in Git history. Browse the [commit history](../../commits/main) on GitHub or run `git log` locally to find and restore any earlier iteration.

