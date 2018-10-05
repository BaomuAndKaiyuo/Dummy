// This is a demo driver with vulnerbale holes like swiss cheese

#include "ntddk.h"
#define __MODULE__ "Dummy"


NTSTATUS
DriverEntry(
	PDRIVER_OBJECT DriverObject,
	PUNICODE_STRING RegistryPath);

VOID
IrpUnloadHandler(
	PDRIVER_OBJECT DriverObject);

#ifdef ALLOC_PRAGMA
#pragma alloc_text(INIT,DriverEntry)
#pragma alloc_text(PAGE, IrpUnloadHandler)
#endif

/// <summary>
/// Driver Entry Point
/// </summary>
/// <param name="DriverObject">The pointer to DRIVER_OBJECT</param>
/// <param name="RegistryPath">The pointer to Unicode string specifying registry path</param>
/// <returns>NTSTATUS</returns>

NTSTATUS
DriverEntry(
	PDRIVER_OBJECT DriverObject,
	PUNICODE_STRING RegistryPath)
{
	//assign driver unload routine
	DriverObject->DriverUnload = IrpUnloadHandler;

	DbgPrint("[m] %s : RegistryPath = %wZ\n", __MODULE__, RegistryPath);
	DbgPrint("[m] %s : Base = 0x%p, Size = 0x%08x\n", __MODULE__, DriverObject->DriverStart, DriverObject->DriverSize);
	DbgPrint("[+] %s.sys loaded\n", __MODULE__);

	return STATUS_SUCCESS;

}//DriverEntry()

 /// <summary>
 /// Driver Unload Routine
 /// </summary>
 /// <param name="DriverObject">The pointer to DRIVER_OBJECT</param>
 /// <returns>No return value</returns>

VOID
IrpUnloadHandler(
	PDRIVER_OBJECT DriverObject)
{
	PAGED_CODE();
	UNREFERENCED_PARAMETER(DriverObject);

	DbgPrint("[+] %s.sys unloaded\n", __MODULE__);
}//IrpUnloadHandler()
