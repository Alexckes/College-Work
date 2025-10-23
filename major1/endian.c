//author: Alex Kesler

unsigned int endian(unsigned int e){
	unsigned int b0,b1,b2,b3,end = 0;
	b0 = (e & 0x000000FF) >> 0;
	b1 = (e & 0x0000FF00) >> 8;
	b2 = (e & 0x00FF0000) >> 16;
	b3 = (e & 0xFF000000) >> 24;
	b0 <<= 24;
	b1 <<= 16;
	b2 <<= 8;
	end = (b0|b1|b2|b3);
	return end;
}