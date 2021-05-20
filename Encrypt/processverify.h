#pragma once

#include "global.h"

#define PROCESS_RULES_BUFFER_TAG 'prBT'
#define PROCESS_RULES_HASH_TAG 'prHT'
#define PROCESS_FILE_BUFFER_TAG 'pfBT'

typedef NTSTATUS(*EptQueryInformationProcess) (
	_In_      HANDLE,
	_In_      PROCESSINFOCLASS,
	_Out_     PVOID,
	_In_      ULONG,
	_Out_opt_ PULONG
	);

extern EptQueryInformationProcess pEptQueryInformationProcess;

//��չ���� , ��Ӣ�ģ��ָ����� , ��Ӣ�ģ����� ���磺txt,docx������count�м�¼����
typedef struct EPT_PROCESS_RULES
{
	LIST_ENTRY ListEntry;
	char TargetProcessName[260];
	char TargetExtension[100];
	int count;
	UCHAR Hash[32];

}EPT_PROCESS_RULES, * PEPT_PROCESS_RULES;

extern LIST_ENTRY ListHead;

extern BOOLEAN CheckHash;

VOID EptListCleanUp();

NTSTATUS ComputeHash(PUCHAR Data, ULONG DataLength, PUCHAR* DataDigestPointer, ULONG* DataDigestLengthPointer);

BOOLEAN EptIsTargetProcess(PFLT_CALLBACK_DATA Data);

BOOLEAN EptIsTargetExtension(PFLT_CALLBACK_DATA Data);