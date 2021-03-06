#include "prefix.hpp"

int main(int argc, char **argv) {
	std::string fname;
	if (argc < 2) {
		fname = "addr_5level.txt";
	} else fname = argv[1];
	AddrParser<wchar_t> AP(fname);
	fprintf(stderr, "load done!\n");
	std::wstring s;
	while (getline(std::wcin, s)) {
		std::vector<const InfoNode<wchar_t> *> result;
		int match_len;
		std::vector<std::wstring> r;
		AP.Search(s, r);
		for (auto &c : r)
			printf("%s ", wstring_to_utf8(c).c_str());
		printf("\n");
	}
	return 0;
}
