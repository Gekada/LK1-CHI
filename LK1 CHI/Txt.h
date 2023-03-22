#include <string>
#include <memory>
#include <fstream>
#include <iostream>
#ifndef TXT_H
#define TXT_H
namespace l1 {
	class Txt {
	public:
		Txt();
		explicit Txt(const std::string& filePath);
		Txt(const Txt& other);
		Txt& operator =	(const Txt& other);
		Txt(Txt&& other) noexcept;
		Txt& operator = (Txt&& other) noexcept;
		~Txt();
		size_t size() const;

	private:
		std::unique_ptr<std::string[]> data;
		size_t dataSize;
	};
}
#endif // !TXT_H

