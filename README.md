# Minecraft Compass — Digital Build

This repo documents my journey building a digital compass inspired by Minecraft, using an LED matrix PCB inside a custom 3D-printed enclosure.

## Preview

### FreeCAD design
<img width="2560" height="1600" alt="Screenshot (175)" src="https://github.com/user-attachments/assets/6ab444fc-6aa3-4832-9ccb-f3087ee8d127" />
<img width="2560" height="1600" alt="Screenshot (174)" src="https://github.com/user-attachments/assets/20066599-eaa0-40aa-98f2-b43e0788c92a" />
<img width="1521" height="944" alt="Screenshot 2025-08-07 164444" src="https://github.com/user-attachments/assets/10c06b61-ea87-46de-8d75-5c1e3a836e66" />

### KiCAD design
<img width="2560" height="1600" alt="Screenshot (173)" src="https://github.com/user-attachments/assets/5ddfef92-3dd9-4b7b-b242-b45bd9158be2" />

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

