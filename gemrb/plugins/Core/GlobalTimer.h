#ifndef GLOBALTIMER_H
#define GLOBALTIMER_H

#include "../../includes/win32def.h"
#include <vector>
#include "Region.h"

class ControlAnimation;

#ifdef WIN32

#ifdef GEM_BUILD_DLL
#define GEM_EXPORT __declspec(dllexport)
#else
#define GEM_EXPORT __declspec(dllimport)
#endif

#else
#define GEM_EXPORT
#endif

struct AnimationRef
{
	ControlAnimation *ctlanim;
	unsigned long  time;
};


class GEM_EXPORT GlobalTimer {
private:
	unsigned long startTime;
	unsigned long interval;

	int fadeToCounter, fadeToMax;
	int fadeFromCounter, fadeFromMax;
	unsigned long waitCounter;
	int shakeCounter;
	unsigned long shakeX, shakeY;
	unsigned int first_animation;
	std::vector<AnimationRef*>  animations;
	//move viewport to this coordinate
	Point goal;
	int speed;
	Region currentVP;
public:
	GlobalTimer(void);
	~GlobalTimer(void);
public:
	void Init();
	void Freeze();
	void Update();
	bool ViewportIsMoving();
	void DoStep(int count);
	void SetMoveViewPort(ieDword x, ieDword y, int spd, bool center);
	void SetFadeToColor(unsigned long Count);
	void SetFadeFromColor(unsigned long Count);
	void SetWait(unsigned long Count);
	void SetScreenShake(unsigned long shakeX, unsigned long shakeY,
		unsigned long Count);
	void AddAnimation(ControlAnimation* ctlanim, unsigned long time);
	void RemoveAnimation(ControlAnimation* ctlanim);
	void ClearAnimations();
	void UpdateAnimations();
};

#endif
