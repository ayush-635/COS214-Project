#ifndef PLANTSEEDCOMMAND_H
#define PLANTSEEDCOMMAND_H

class PlantSeedCommand : Duty {

public:
	Plant* seed;

	PlantSeedCommand(Plant* seed);

	void executeDuty(PlantableArea* area);
};

#endif
