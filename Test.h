#pragma once
class Test
{
public:
	Test();
	bool default_constructor();
	bool long_constructor();
	bool char_constructor();
	bool char_constructor_symbols();
	bool addition_a_b();
	bool addition_b_a();
	bool addition_a_null();
	bool addition_discharge_transfer();
	bool mult_a_b();
	bool mult_b_a();
	bool mult_pos_a_null();
	bool sub_a_b();
	bool sub_b_a();
	bool sub_a_a();
	bool sub_discharge_transfer();
	bool sub_discharge_transfer_v2();
	bool convert_to_2();
	bool convert_to_8();
	bool convert_to_16();
	bool convert_to_17();
	bool div_a_b();
	bool div_b_a();
	bool div_a_0();
	bool div_0_a();
	bool div_a_a();
	int suc;
	int fail;
};


