#ifndef DISPLAY_H
#define DISPLAY_H

class Display
{
public:
	static const int width = 10;
	static const int height = 10;
	static const int depth = 4;
	static const int num_registers = ((width * height) + depth) / 8 + 1;
	
	Display();
	
	inline void pxOn(int num, int layer)
	{
		data[layer][num / 8] |= 1 << (num % 8);
	}

	inline void pxOn(int x, int y, int layer)
	{
		pxOn(x + (y * 10), layer);
	}
	  
	inline void clear()
	{
		memset(data, 0, sizeof(data));
	}

	void wall_horizontal(int a);
	void wall_vertical(int a);
	void wall_flat(int a);

	void draw();
	inline void draw(int times)
	{
		for (int i = 0; i < times; ++i) draw();
	}
  
private:
	byte data[depth][num_registers];

	byte pin_data;
	byte pin_clock;
	byte pin_latch;
	byte pin_clear;
	byte pin_enable;
};

#endif
