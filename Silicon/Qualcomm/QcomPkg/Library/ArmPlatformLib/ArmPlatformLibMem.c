/**
  Copyright (c) 2011, ARM Limited. All rights reserved.

  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#include <Library/ArmPlatformLib.h>
#include <Library/DebugLib.h>

#include <Library/DeviceMemoryMapLib.h>

/**
  Return the Virtual Memory Map of your Device.

  This Virtual Memory Map is used by MemoryInitPei Module to initialize the MMU on your Device.

  @param[out]   VirtualMemoryMap    Array of ARM_MEMORY_REGION_DESCRIPTOR Describing a Physical-to-Virtual Memory Mapping.
                                    This Array must be ended by a zero-filled Entry.
**/
VOID
ArmPlatformGetVirtualMemoryMap (IN ARM_MEMORY_REGION_DESCRIPTOR **VirtualMemoryMap)
{
  ARM_MEMORY_REGION_DESCRIPTOR     MemoryTable[MAX_ARM_MEMORY_REGION_DESCRIPTOR_COUNT];
  PARM_MEMORY_REGION_DESCRIPTOR_EX MemoryDescriptorEx = GetDeviceMemoryMap();
  UINTN                            Index              = 0;

  // Run through each memory descriptor
  while (MemoryDescriptorEx->Length != 0) {
    if (MemoryDescriptorEx->HobOption == HobOnlyNoCacheSetting) {
      MemoryDescriptorEx++;
      continue;
    }

    if (MemoryDescriptorEx->HobOption == AddDynamicMem) {
      MemoryDescriptorEx++;
      continue;
    }

    ASSERT(Index < MAX_ARM_MEMORY_REGION_DESCRIPTOR_COUNT);

    MemoryTable[Index].PhysicalBase = MemoryDescriptorEx->Address;
    MemoryTable[Index].VirtualBase  = MemoryDescriptorEx->Address;
    MemoryTable[Index].Length       = MemoryDescriptorEx->Length;
    MemoryTable[Index].Attributes   = MemoryDescriptorEx->ArmAttributes;

    Index++;
    MemoryDescriptorEx++;
  }

  // Last one (terminator)
  ASSERT(Index < MAX_ARM_MEMORY_REGION_DESCRIPTOR_COUNT);
  MemoryTable[Index].PhysicalBase = 0;
  MemoryTable[Index].VirtualBase  = 0;
  MemoryTable[Index].Length       = 0;
  MemoryTable[Index].Attributes   = 0;

  *VirtualMemoryMap = MemoryTable;
}
