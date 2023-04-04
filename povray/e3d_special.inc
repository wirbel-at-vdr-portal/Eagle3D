/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/
#include "e3d_tools.inc"
#include "BOARDS/digilent.inc"            // 06.04.2022, add Digilent S6 FPGA devboard
#include "BUZZER/TDB.inc"                 // 29.03.2023, move SPC_BUZZER_TDB to BUZZER/TDB.inc
#include "CONNECTOR/wirejumper.inc"       // 02.04.2023, move wire jumpers to CONNECTOR/wirejumper.inc
#include "CRYSTAL/ceramic_resonator.inc"  // 29.03.2023, move ceramic resonators to CRYSTAL/ceramic_resonator.inc
#include "CRYSTAL/crystal.inc"            // 30.03.2023, move crystals to CRYSTAL/crystal.inc
#include "CRYSTAL/oscillator.inc"         // 25.03.2023, add 3.2 x 2.5mm oscillator
#include "DCDC/Murata.inc"                // 02.04.2023, move DC/DC to DCDC/Murata.inc
#include "DCDC/Traco.inc"                 // 06.04.2022, move DC/DC to DCDC/traco.inc
#include "FUSE/SHK20L.inc"                // 30.03.2023, move fuses to subfolder
#include "FUSE/SHK20Q.inc"                // 30.03.2023, move fuses to subfolder
#include "HEATSINK/KL195.inc"             // 30.03.2023, move heatsinks to subfolder
#include "HEATSINK/RAxx.inc"              // 30.03.2023, move heatsinks to subfolder
#include "HEATSINK/SK96.inc"              // 30.03.2023, move heatsinks to subfolder
#include "HEATSINK/SK104.inc"             // 30.03.2023, move heatsinks to subfolder
#include "HEATSINK/viewcom.inc"           // 30.03.2023, move heatsinks to subfolder
#include "INDUCTOR/CTC-coils.inc"         // 04.04.2023, move inductors to subfolder
#include "INDUCTOR/L_5MM_S.inc"           // 03.04.2023, move inductors to subfolder
#include "INDUCTOR/L_EF_core.inc"         // 03.04.2023, move inductors to subfolder
#include "INDUCTOR/Murata.inc"            // 03.04.2023, move inductors to subfolder
#include "INDUCTOR/toroids.inc"           // 03.04.2023, move inductors to subfolder
#include "INDUCTOR/Tyco.inc"              // 03.04.2023, move inductors to subfolder
#include "INDUCTOR/WuerthElektronik.inc"  // 03.04.2023, move inductors to subfolder
#include "OPTO/Avago.inc"                 // 04.04.2023, move opto to subfolder
#include "OPTO/lightpipe.inc"             // 02.04.2023, move lightpipe to subfolder
#include "OPTO/Toshiba.inc"               // 04.04.2023, move opto to subfolder
#include "RELAY/Celduc.inc"               // 31.03.2023, move relays to subfolder
#include "RELAY/Omron.inc"                // 31.03.2023, move relays to subfolder
#include "RELAY/Panasonic.inc"            // 31.03.2023, move relays to subfolder
#include "RELAY/Schrack.inc"              // 31.03.2023, move relays to subfolder
#include "RELAY/SIL.inc"                  // 31.03.2023, move relays to subfolder
