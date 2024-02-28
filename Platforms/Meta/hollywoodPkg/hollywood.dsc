##
#
#  Copyright (c) 2011 - 2022, ARM Limited. All rights reserved.
#  Copyright (c) 2014, Linaro Limited. All rights reserved.
#  Copyright (c) 2015 - 2020, Intel Corporation. All rights reserved.
#  Copyright (c) 2018, Bingxing Wang. All rights reserved.
#  Copyright (c) Microsoft Corporation.
#
#  SPDX-License-Identifier: BSD-2-Clause-Patent
#
##

################################################################################
#
# Defines Section - statements that will be processed to create a Makefile.
#
################################################################################
[Defines]
  PLATFORM_NAME                  = hollywood
  PLATFORM_GUID                  = 2085688f-c531-4968-9e88-44937663d977
  PLATFORM_VERSION               = 0.1
  DSC_SPECIFICATION              = 0x00010005
  OUTPUT_DIRECTORY               = Build/hollywoodPkg
  SUPPORTED_ARCHITECTURES        = AARCH64
  BUILD_TARGETS                  = RELEASE|DEBUG
  SKUID_IDENTIFIER               = DEFAULT
  FLASH_DEFINITION               = hollywoodPkg/hollywood.fdf
  USE_DISPLAYDXE                 = 0
  AB_SLOT_SUPPORT                = 0

  # If your SoC has multimple variants define the Number here
  # If not don't add this Define
  SOC_TYPE                       = 0

# If your SoC has multimple variants keep this Build Option
# If not don't add "-DSOC_TYPE=$(SOC_TYPE)" to the Build Options.
[BuildOptions.common]
  *_*_*_CC_FLAGS = -DSOC_TYPE=$(SOC_TYPE)

[LibraryClasses.common]
  DeviceMemoryMapLib|hollywoodPkg/Library/DeviceMemoryMapLib/DeviceMemoryMapLib.inf
  DeviceConfigurationMapLib|hollywoodPkg/Library/DeviceConfigurationMapLib/DeviceConfigurationMapLib.inf

[PcdsFixedAtBuild.common]
  gArmTokenSpaceGuid.PcdSystemMemoryBase|0x80000000                 # Starting address

  gEfiMdeModulePkgTokenSpaceGuid.PcdFirmwareVendor|L"arminask" # Device Maintainer

  gArmTokenSpaceGuid.PcdCpuVectorBaseAddress|0x9FF8C000

  gEmbeddedTokenSpaceGuid.PcdPrePiStackBase|0x9FF90000
  gEmbeddedTokenSpaceGuid.PcdPrePiStackSize|0x00040000            # 256K stack

  # SmBios
  gQcomPkgTokenSpaceGuid.PcdSmbiosSystemVendor|"Meta"
  gQcomPkgTokenSpaceGuid.PcdSmbiosSystemModel|"Meta Quest 2"
  gQcomPkgTokenSpaceGuid.PcdSmbiosSystemRetailModel|"hollywood"
  gQcomPkgTokenSpaceGuid.PcdSmbiosSystemRetailSku|"Quest_2_hollywood"
  gQcomPkgTokenSpaceGuid.PcdSmbiosBoardModel|"Quest 2"

  # Simple FrameBuffer
  gQcomPkgTokenSpaceGuid.PcdMipiFrameBufferWidth|1920
  gQcomPkgTokenSpaceGuid.PcdMipiFrameBufferHeight|3664
  gQcomPkgTokenSpaceGuid.PcdMipiFrameBufferColorDepth|32

  # Dynamic RAM
  gQcomPkgTokenSpaceGuid.PcdRamPartitionBase|0xB0000000

  # SD Card
  gQcomPkgTokenSpaceGuid.PcdSDCardSlotPresent|FALSE

  # Usb Init
  gQcomPkgTokenSpaceGuid.PcdUSBInitOnBoot|TRUE

[PcdsDynamicDefault.common]
  gEfiMdeModulePkgTokenSpaceGuid.PcdVideoHorizontalResolution|1920
  gEfiMdeModulePkgTokenSpaceGuid.PcdVideoVerticalResolution|3664
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupVideoHorizontalResolution|1920
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupVideoVerticalResolution|3664
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupConOutColumn|240
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupConOutRow|193
  gEfiMdeModulePkgTokenSpaceGuid.PcdConOutColumn|240
  gEfiMdeModulePkgTokenSpaceGuid.PcdConOutRow|193

!include SM8250Pkg/SM8250Pkg.dsc.inc
