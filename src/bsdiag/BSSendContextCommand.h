#pragma once

#include "bsdiag/BSSherlockCommand.h"

class BSSendContextCommand : public BSSherlockCommand {
	u8 unk_0x4;
	char* pContext;
	uint iContextSize;

  public:
	BSSendContextCommand();
	virtual ~BSSendContextCommand();
	virtual bool PerformCommand(char*, uint);
	virtual uint FillResponceBuffer(void*);
	virtual void* GetResponceBuffer();
	virtual uint GetResponceBufferSize();
	virtual SHERLOCK_COMMAND GetResponceType();
	virtual bool IsMultiPart();
	virtual bool IsMultiPartComplete();
};
