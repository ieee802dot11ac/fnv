#pragma once

#include "fallout_shared/enums.h"
#include "types.h"

enum BS_TASK_STATE : int {
	BS_TASK_STATE_PENDING = 0x0000,
	BS_TASK_STATE_QUEUED = 0x0001,
	BS_TASK_STATE_MOVING = 0x0002,
	BS_TASK_STATE_RUNNING = 0x0003,
	BS_TASK_STATE_FINISHED = 0x0004,
	BS_TASK_STATE_COMPLETED = 0x0005,
	BS_TASK_STATE_CANCELED = 0x0006,
	BS_TASK_STATE_FORCE_DWORD = 0x7fffffff,
};

template <typename T> class BSTask {
	BSTask(const BSTask<T>&);
	BSTask();
	virtual ~BSTask();
	virtual void Run();
	virtual void Finish();
	virtual void Cancel(BS_TASK_STATE, void*);
	bool GetTaskPending();
	bool GetTaskFinished();
	bool GetTaskCompleted();
	bool GetTaskCanceled();
	void SetTaskFinished();
	void SetTaskCanceled();
	T GetKey();
	virtual bool GetDescription(char*, uint);
	BS_TASK_STATE GetState();
	bool SwitchState(BS_TASK_STATE, BS_TASK_STATE);
	void IncRefCount();
	void DecRefCount();
	uint GetRefCount();

	static uint GetTotalBSTaskCount();

  protected:
	volatile int iRefCount; // 0x08
	BS_TASK_STATE eState;	// 0x0c
	T Key;					// 0x10
};

class IOTask : public BSTask<s64> {
  public:
	IOTask(IO_TASK_PRIORITY);
	virtual void PostProcess();
	unsigned char GetPriority();
	void SetPriority(unsigned char);
	IO_TASK_PRIORITY GetIOTaskPriority();
	void SetIOTaskPriority(IO_TASK_PRIORITY);
	virtual void GenerateKey();
	void SetKey(char, uint, unsigned char, unsigned short);
	void IncrementCounter();
	unsigned short GetNextCounter();
	uint GetNextOffset();
	virtual void Requeue(IO_TASK_PRIORITY);
	void AddToPostProcessQueue();
	virtual ~IOTask();

	static unsigned char GetFileIndexFromKey(s64&);
	static uint GetOffsetFromKey(s64&);
	static unsigned char GetPriorityFromKey(s64&);

  protected:
	static volatile int iStaticCounter;
	static volatile int iStaticOffset;
};
