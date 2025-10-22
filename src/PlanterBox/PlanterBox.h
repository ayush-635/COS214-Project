#ifndef PLANTERBOX_H
#define PLANTERBOX_H

class PlanterBox : PlantableArea {

public:
	Plant* plant;

	void populate(Plant* plant);

	Plant* removePlant(Plant* plant);

	void water(int unit);

	void giveMedicine();
};

#endif
