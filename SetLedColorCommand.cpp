#include "SetLedColorCommand.h"

SetLedColorCommand::SetLedColorCommand()
{
	name = "set-led-color";
	argument_list = {COLOR_RED_TEXT, COLOR_GREEN_TEXT, COLOR_BLUE_TEXT};
}

SetLedColorCommand::~SetLedColorCommand()
{

}

pair < string, bool > SetLedColorCommand::applyCommand(Led* led, string argument)
{
	map <string, LedColor> reverse_color_map;
	reverse_color_map[COLOR_RED_TEXT] = COLOR_RED;
	reverse_color_map[COLOR_GREEN_TEXT] = COLOR_GREEN;
	reverse_color_map[COLOR_BLUE_TEXT] = COLOR_BLUE;
	
	set < string> arg_list = getArgumentList();
	auto it = arg_list.find(argument);
	bool status = false;
	if (it != arg_list.end()) {
		status = true;
		led->setColor(reverse_color_map[argument]);
	}
		

	return make_pair("", status);
}