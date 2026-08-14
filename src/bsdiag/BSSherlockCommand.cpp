#include "BSSherlockCommand.h"

BSSherlockCommand::BSSherlockCommand() {}

BSSherlockCommand::~BSSherlockCommand() {}

bool BSSherlockCommand::PerformCommand(char*, uint) { return true; }

uint BSSherlockCommand::FillResponceBuffer(void*) { return 0; }

bool BSSherlockCommand::IsMultiPart() { return false; }

// the rest got merged together rip bozo

void* BSSherlockCommand::GetResponceBuffer() { return 0; }

uint BSSherlockCommand::GetResponceBufferSize() { return 0; }

BSSherlockCommand::SHERLOCK_COMMAND BSSherlockCommand::GetResponceType() {
	return BSSherlockCommand::SC_SEND_COMMAND;
}

bool BSSherlockCommand::IsMultiPartComplete() { return 0; }
