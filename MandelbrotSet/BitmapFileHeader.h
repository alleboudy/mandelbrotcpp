#ifndef BITMAPFILHEADER_H_
#define BITMAPILEHEADER_H_

#include <cstdint>//insure a 32bit int
#pragma pack(2)//align everything on 2bytes boundaries, no padding
namespace alleboudy {
	struct BitmapFileHeader {
		char header[2]{ 'B', 'M' };
		int32_t fileSize;
		int32_t reserved{ 0 };
		int32_t dataOffset;
	};
}
#endif // BITMAPFILHEADER_H_
