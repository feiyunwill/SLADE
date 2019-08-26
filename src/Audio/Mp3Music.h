#pragma once

#include <SFML/Audio.hpp>
#include <mpg123.h>

class Mp3Music : public sf::SoundStream
{
public:
	Mp3Music();
	~Mp3Music();

	bool     openFromFile(const std::string& filename);
	bool     loadFromMemory(void* data, size_t size_in_bytes);
	sf::Time duration() const;

protected:
	bool onGetData(Chunk& data) override;
	void onSeek(sf::Time time_offset) override;

private:
	mpg123_handle* handle_      = nullptr;
	size_t         buffer_size_ = 0;
	unsigned char* buffer_      = nullptr;
	sf::Mutex      mutex_;
	long           sampling_rate_ = 0;
};
