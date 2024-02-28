APRIORI DXE {

  # First, install the PCD driver and call DxeInit
  INF MdeModulePkg/Core/Dxe/DxeMain.inf
  INF MdeModulePkg/Universal/PCD/Dxe/Pcd.inf

  INF Binaries/hollywood/QcomPkg/Drivers/EnvDxe/EnvDxe.inf

  INF MdeModulePkg/Universal/ReportStatusCodeRouter/RuntimeDxe/ReportStatusCodeRouterRuntimeDxe.inf
  INF MdeModulePkg/Universal/StatusCodeHandler/RuntimeDxe/StatusCodeHandlerRuntimeDxe.inf
  INF MdeModulePkg/Core/RuntimeDxe/RuntimeDxe.inf

  # Next, install cpu protocol and enable the interrupt controller
  INF ArmPkg/Drivers/CpuDxe/CpuDxe.inf
  INF ArmPkg/Drivers/ArmGic/ArmGicDxe.inf

  # Core Drivers
  INF EmbeddedPkg/MetronomeDxe/MetronomeDxe.inf
  INF ArmPkg/Drivers/TimerDxe/TimerDxe.inf
  INF ArmPkg/Drivers/ArmPsciMpServicesDxe/ArmPsciMpServicesDxe.inf

  INF Binaries/hollywood/QcomPkg/Drivers/SmemDxe/SmemDxe.inf

  INF QcomPkg/Drivers/DynamicRAMDxe/DynamicRAMDxe.inf

  INF Binaries/hollywood/QcomPkg/Drivers/DALSYSDxe/DALSYSDxe.inf
  INF Binaries/hollywood/QcomPkg/Drivers/HWIODxe/HWIODxe.inf
  INF Binaries/hollywood/QcomPkg/Drivers/ChipInfoDxe/ChipInfoDxe.inf
  INF Binaries/hollywood/QcomPkg/Drivers/PlatformInfoDxe/PlatformInfoDxe.inf
  INF Binaries/hollywood/QcomPkg/Drivers/HALIOMMUDxe/HALIOMMUDxe.inf
  INF Binaries/hollywood/QcomPkg/Drivers/ULogDxe/ULogDxe.inf
  INF Binaries/hollywood/QcomPkg/Drivers/CmdDbDxe/CmdDbDxe.inf
  INF Binaries/hollywood/QcomPkg/Drivers/PwrUtilsDxe/PwrUtilsDxe.inf
  INF Binaries/hollywood/QcomPkg/Drivers/NpaDxe/NpaDxe.inf
  INF Binaries/hollywood/QcomPkg/Drivers/RpmhDxe/RpmhDxe.inf
  INF Binaries/hollywood/QcomPkg/Drivers/PdcDxe/PdcDxe.inf
  INF Binaries/hollywood/QcomPkg/Drivers/VcsDxe/VcsDxe.inf
  INF Binaries/hollywood/QcomPkg/Drivers/ClockDxe/ClockDxe.inf

  INF QcomPkg/Drivers/ClockSpeedUpDxe/ClockSpeedUpDxe.inf

  INF Binaries/hollywood/QcomPkg/Drivers/SPMIDxe/SPMIDxe.inf
  INF Binaries/hollywood/QcomPkg/Drivers/ShmBridgeDxe/ShmBridgeDxeLA.inf
  #INF Binaries/hollywood/QcomPkg/Drivers/TzDxe/ScmDxeLA.inf
  INF Binaries/hollywood/QcomPkg/Drivers/TLMMDxe/TLMMDxe.inf
  INF Binaries/hollywood/QcomPkg/Drivers/ResetRuntimeDxe/ResetRuntimeDxe.inf
  INF Binaries/hollywood/QcomPkg/Drivers/PmicDxe/PmicDxeLa.inf
  INF Binaries/hollywood/MdeModulePkg/Universal/Disk/DiskIoDxe/DiskIoDxe.inf
  INF Binaries/hollywood/MdeModulePkg/Universal/Disk/PartitionDxe/PartitionDxe.inf

  INF MdeModulePkg/Universal/Disk/UnicodeCollation/EnglishDxe/EnglishDxe.inf

  INF Binaries/hollywood/QcomPkg/Drivers/SdccDxe/SdccDxe.inf
  #INF Binaries/hollywood/QcomPkg/Drivers/UFSDxe/UFSDxe.inf

  INF FatPkg/EnhancedFatDxe/Fat.inf

  #INF Binaries/hollywood/QcomPkg/Drivers/TzDxe/TzDxeLA.inf

  INF MdeModulePkg/Universal/Variable/RuntimeDxe/VariableRuntimeDxe.inf

  INF Binaries/hollywood/QcomPkg/Drivers/FeatureEnablerDxe/FeatureEnablerDxe.inf
  INF Binaries/hollywood/QcomPkg/Drivers/QcomWDogDxe/QcomWDogDxe.inf
  INF Binaries/hollywood/QcomPkg/Drivers/DDRInfoDxe/DDRInfoDxe.inf
  INF Binaries/hollywood/QcomPkg/Drivers/SPIDxe/SPIDxe.inf
  INF Binaries/hollywood/QcomPkg/Drivers/I2CDxe/I2CDxe.inf

!if $(USE_DISPLAYDXE) == 1
  INF Binaries/hollywood/QcomPkg/Drivers/DisplayDxe/DisplayDxe.inf
!else
  INF QcomPkg/Drivers/SimpleFbDxe/SimpleFbDxe.inf
!endif

  INF Binaries/hollywood/QcomPkg/Drivers/PILProxyDxe/PILProxyDxe.inf
  #INF Binaries/hollywood/QcomPkg/Drivers/PILDxe/PILDxe.inf
  INF Binaries/hollywood/QcomPkg/Drivers/SPSSDxe/SPSSDxe.inf
!if $(USE_DISPLAYDXE) == 1
  INF Binaries/hollywood/QcomPkg/Drivers/CPRDxe/CPRDxe.inf
!endif

  INF MdeModulePkg/Universal/WatchdogTimerDxe/WatchdogTimer.inf
  INF MdeModulePkg/Universal/SecurityStubDxe/SecurityStubDxe.inf
  INF EmbeddedPkg/EmbeddedMonotonicCounter/EmbeddedMonotonicCounter.inf
  INF EmbeddedPkg/RealTimeClockRuntimeDxe/RealTimeClockRuntimeDxe.inf
  INF MdeModulePkg/Universal/PrintDxe/PrintDxe.inf
  INF MdeModulePkg/Universal/DevicePathDxe/DevicePathDxe.inf
  INF MdeModulePkg/Universal/CapsuleRuntimeDxe/CapsuleRuntimeDxe.inf
  INF MdeModulePkg/Universal/HiiDatabaseDxe/HiiDatabaseDxe.inf

  INF Binaries/hollywood/QcomPkg/Drivers/FontDxe/FontDxe.inf

  INF MdeModulePkg/Universal/BdsDxe/BdsDxe.inf

  INF Binaries/hollywood/QcomPkg/Drivers/AdcDxe/AdcDxe.inf
  INF Binaries/hollywood/QcomPkg/Drivers/UsbPwrCtrlDxe/UsbPwrCtrlDxe.inf
  INF Binaries/hollywood/QcomPkg/Drivers/QcomChargerDxe/QcomChargerDxeLA.inf
  INF Binaries/hollywood/QcomPkg/Drivers/ChargerExDxe/ChargerExDxe.inf
  INF Binaries/hollywood/QcomPkg/Drivers/UsbfnDwc3Dxe/UsbfnDwc3Dxe.inf
  INF Binaries/hollywood/QcomPkg/Drivers/XhciPciEmulationDxe/XhciPciEmulationDxe.inf
  INF Binaries/hollywood/QcomPkg/Drivers/XhciDxe/XhciDxe.inf

  INF MdeModulePkg/Bus/Usb/UsbBusDxe/UsbBusDxe.inf
  INF MdeModulePkg/Bus/Usb/UsbKbDxe/UsbKbDxe.inf
  INF MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe.inf

  INF Binaries/hollywood/QcomPkg/Drivers/UsbMsdDxe/UsbMsdDxe.inf
  INF Binaries/hollywood/QcomPkg/Drivers/UsbDeviceDxe/UsbDeviceDxe.inf
  INF Binaries/hollywood/QcomPkg/Drivers/UsbConfigDxe/UsbConfigDxe.inf
  INF Binaries/hollywood/QcomPkg/Drivers/UsbInitDxe/UsbInitDxe.inf
  INF Binaries/hollywood/QcomPkg/Drivers/ButtonsDxe/ButtonsDxe.inf
  INF Binaries/hollywood/QcomPkg/Drivers/TsensDxe/TsensDxe.inf
  INF Binaries/hollywood/QcomPkg/Drivers/LimitsDxe/LimitsDxe.inf
  INF Binaries/hollywood/QcomPkg/Drivers/GpiDxe/GpiDxe.inf
  INF Binaries/hollywood/QcomPkg/Drivers/HashDxe/HashDxe.inf
  INF Binaries/hollywood/QcomPkg/Drivers/CipherDxe/CipherDxe.inf
  INF Binaries/hollywood/QcomPkg/Drivers/MacDxe/MacDxe.inf
  INF Binaries/hollywood/QcomPkg/Drivers/RNGDxe/RngDxe.inf

  INF EmbeddedPkg/SimpleTextInOutSerial/SimpleTextInOutSerial.inf
  INF MdeModulePkg/Universal/Console/ConPlatformDxe/ConPlatformDxe.inf
  INF MdeModulePkg/Universal/Console/ConSplitterDxe/ConSplitterDxe.inf
  INF MdeModulePkg/Universal/Console/GraphicsConsoleDxe/GraphicsConsoleDxe.inf
}
