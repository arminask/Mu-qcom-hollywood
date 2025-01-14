/**
  Copyright (c) 2011-2012, ARM Limited. All rights reserved.

  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#include <Library/ArmLib.h>
#include <Library/ArmPlatformLib.h>
#include <Library/SoCPlatformLib.h>

#include "InitializationUtils.h"

/**
  Return the Current Boot Mode.

  This Function Returns the Boot Reason on the Device.
**/
EFI_BOOT_MODE
ArmPlatformGetBootMode (VOID)
{
  return BOOT_WITH_DEFAULT_SETTINGS;
}

/**
  Initialize Controllers that must Setup in the Normal World.

  This Function is called by the ArmPlatformPkg/PrePi or ArmPlatformPkg/PlatformPei in the PEI Phase.
**/
RETURN_STATUS
ArmPlatformInitialize (IN UINTN MpId)
{
  if (!ArmPlatformIsPrimaryCore (MpId)) {
    return RETURN_SUCCESS;
  }

  EarlyInitialization();

  return RETURN_SUCCESS;
}

EFI_STATUS
PrePeiCoreGetMpCoreInfo (
  OUT UINTN          *CoreCount,
  OUT ARM_CORE_INFO **ArmCoreTable)
{
  if (ArmIsMpCore ()) {
    *CoreCount    = PcdGet32(PcdCoreCount);
    *ArmCoreTable = GetCoreTable();

    return EFI_SUCCESS;
  } else {
    return EFI_UNSUPPORTED;
  }
}

ARM_MP_CORE_INFO_PPI mMpCoreInfoPpi = { PrePeiCoreGetMpCoreInfo };

EFI_PEI_PPI_DESCRIPTOR  gPlatformPpiTable[] = {
  {
    EFI_PEI_PPI_DESCRIPTOR_PPI,
    &gArmMpCoreInfoPpiGuid,
    &mMpCoreInfoPpi
  }
};

VOID
ArmPlatformGetPlatformPpiList (
  OUT UINTN                   *PpiListSize,
  OUT EFI_PEI_PPI_DESCRIPTOR **PpiList)
{
  if (ArmIsMpCore ()) {
    *PpiListSize = sizeof (gPlatformPpiTable);
    *PpiList     = gPlatformPpiTable;
  } else {
    *PpiListSize = 0;
    *PpiList     = NULL;
  }
}
