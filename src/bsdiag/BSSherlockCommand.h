#pragma once
#include "bscore/memorymanager.h"
#include "types.h"

class BSSherlockCommand { /* Size=0x4 */
  public:
	enum SHERLOCK_COMMAND {
		SC_SEND_COMMAND = 0,
		SC_NORMAL_RESPONCE = 1,
		SC_BINARY_RESPONCE = 2,
		SC_MULTIPART_RESPONCE = 3,
		SC_BINARY_RECIEVE = 4,
	};

	BSSherlockCommand();
	virtual ~BSSherlockCommand();
	virtual bool PerformCommand(char*, uint);
	virtual uint FillResponceBuffer(void*);
	virtual void* GetResponceBuffer();
	virtual uint GetResponceBufferSize();
	virtual SHERLOCK_COMMAND GetResponceType() { return SC_SEND_COMMAND; }
	virtual bool IsMultiPart() { return false; }
	virtual bool IsMultiPartComplete() { return true; }

	BS_MEM_OVERLOADS
};
