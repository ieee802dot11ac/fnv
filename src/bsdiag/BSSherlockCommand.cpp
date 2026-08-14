#include "BSSherlockCommand.h"

BSSherlockCommand::BSSherlockCommand() {}

BSSherlockCommand::~BSSherlockCommand() {}

bool BSSherlockCommand::PerformCommand(char*, uint) { return true; }

uint BSSherlockCommand::FillResponceBuffer(void*) { return 0; }

// the rest got merged together rip bozo

void* BSSherlockCommand::GetResponceBuffer() { return 0; }

uint BSSherlockCommand::GetResponceBufferSize() { return 0; }
