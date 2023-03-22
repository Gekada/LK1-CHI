#include "Txt.h"
namespace l1 {
	Txt::Txt() : data(nullptr), dataSize(0) {}

	Txt::Txt(const std::string& filePath) : data(nullptr), dataSize(0) {
		std::ifstream file(filePath);
		if (file.good()) {
			std::string tempString;
			while (std::getline(file,tempString)) {
				dataSize++;
			}
			file.clear();
			file.seekg(0);
			data = std::make_unique<std::string[]>(dataSize);
			int i = 0;
			while (std::getline(file, tempString)) {
				data[i] = tempString;
				i++;
			}
		}
		else {
			std::cout << "error opening file";
		}
		file.close();
	}

	Txt::Txt(const Txt& other) : data(std::make_unique<std::string[]>(other.dataSize)), dataSize(other.dataSize) {
		for (int i = 0; i < dataSize; i++) {
			data[i] = other.data[i];
		}
	}

	Txt& Txt::operator=(const Txt& other)
	{
		if (this != &other) {
			data = std::make_unique<std::string[]>(other.dataSize);
			dataSize = other.dataSize;
			for (int i = 0; i < dataSize; i++) {
				data[i] = other.data[i];
			}
		}
		return *this;
	}

	Txt::Txt(Txt&& other) noexcept : data(std::move(other.data)), dataSize(other.dataSize)
	{
		other.data = nullptr;
		other.dataSize = 0;
	}

	Txt& Txt::operator=(Txt&& other) noexcept
	{
		if (this != &other) {
			data = std::move(other.data);
			dataSize = other.dataSize;
			other.data = nullptr;
			other.dataSize = 0;
		}
		return *this;
	}

	Txt::~Txt(){}

	size_t Txt::size() const
	{
		return dataSize;
	}
}