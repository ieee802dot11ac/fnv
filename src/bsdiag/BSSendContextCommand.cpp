#include "BSSendContextCommand.h"

BSSendContextCommand::BSSendContextCommand()
	: unk_0x4(0), pContext(0), iContextSize(0) {}

BSSendContextCommand::~BSSendContextCommand() { delete pContext; }

bool BSSendContextCommand::PerformCommand(char* apData, uint aiSize) {
	return true;
}

void* BSSendContextCommand::GetResponceBuffer() { return pContext; }

uint BSSendContextCommand::GetResponceBufferSize() { return iContextSize; }

BSSherlockCommand::SHERLOCK_COMMAND BSSendContextCommand::GetResponceType() {
	return BSSherlockCommand::SC_BINARY_RESPONCE;
}
