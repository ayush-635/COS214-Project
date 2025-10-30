#ifndef PLANTERBOXCOLLECTION_H
#define PLANTERBOXCOLLECTION_H

class PlanterBoxCollection : PlantableArea {

public:
	std::list<PlantableArea*> children;

	void populate(Plant* plant);

	void populate(Plant* plant, int plantBoxIndex);

	void addPlantableArea(PlantableArea* area);

	void removePlantableArea(PlantableArea* area);

	void removePlant(Plant* plant, int plantBoxIndex);

	Plant* removePlant(Plant* plant);

	void water(int unit);

	void giveMedicine();

	void giveFertilizer(int units);
};

#endif
