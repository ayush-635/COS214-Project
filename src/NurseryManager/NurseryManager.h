#ifndef NURSERYMANAGER_H
#define NURSERYMANAGER_H

class NurseryManager {

private:
	SpaceBuilder* builder;

public:
	void constructSmallSpace();

	void constructMediumSpace();

	void constructBigSpace();
};

#endif
