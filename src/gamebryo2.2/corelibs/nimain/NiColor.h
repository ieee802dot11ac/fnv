#pragma once

#include "nimain/nistream.h"

class NiColor {
  public:
	float r; // 0x0
	float g; // 0x4
	float b; // 0x8
	static const NiColor WHITE;
	static const NiColor BLACK;
	static const NiColor RED;
	static const NiColor GREEN;
	static const NiColor BLUE;
	static const NiColor YELLOW;
	static const NiColor PURPLE;
	static const NiColor CYAN;

	NiColor(float, float, float);
	bool operator==(const NiColor&) const;
	bool operator!=(const NiColor&) const;
	NiColor operator+(const NiColor&) const;
	NiColor operator-() const;
	NiColor operator-(const NiColor&) const;
	NiColor operator*(const NiColor&) const;
	NiColor operator*(float) const;
	NiColor operator/(const NiColor&) const;
	NiColor operator/(float) const;
	NiColor& operator+=(const NiColor&);
	NiColor& operator-=(const NiColor&);
	NiColor& operator*=(const NiColor&);
	NiColor& operator*=(float);
	NiColor& operator/=(const NiColor&);
	NiColor& operator/=(float);
	void Clamp();
	void Scale();
	void LoadBinary(NiStream&);
	void SaveBinary(NiStream&);
	char* GetViewerString(const char*) const;
	float Luminance();

	static void LoadBinary(NiStream&, NiColor*, unsigned int);
	static void SaveBinary(NiStream&, NiColor*, unsigned int);
};

class NiColorA {
  public:
	float r; // 0x0
	float g; // 0x4
	float b; // 0x8
	float a; // 0xc
	static const NiColorA WHITE;
	static const NiColorA BLACK;
	static const NiColorA RED;
	static const NiColorA GREEN;
	static const NiColorA BLUE;
	static const NiColorA YELLOW;
	static const NiColorA PURPLE;
	static const NiColorA CYAN;

	NiColorA(float, float, float, float);
	bool operator==(const NiColorA&) const;
	bool operator!=(const NiColorA&) const;
	NiColorA operator+(const NiColorA&) const;
	NiColorA operator-() const;
	NiColorA operator-(const NiColorA&) const;
	NiColorA operator*(const NiColorA&) const;
	NiColorA operator*(float) const;
	NiColorA operator/(const NiColorA&) const;
	NiColorA operator/(float) const;
	NiColorA& operator+=(const NiColorA&);
	NiColorA& operator-=(const NiColorA&);
	NiColorA& operator*=(const NiColorA&);
	NiColorA& operator*=(float);
	NiColorA& operator/=(const NiColorA&);
	NiColorA& operator/=(float);
	void Clamp();
	void Scale();
	void LoadBinary(NiStream&);
	void SaveBinary(NiStream&);
	char* GetViewerString(const char*) const;
	float Luminance();

	static void LoadBinary(NiStream&, NiColorA*, unsigned int);
	static void SaveBinary(NiStream&, NiColorA*, unsigned int);
};
