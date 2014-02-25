#ifndef _CONSTRAINTS_H
#define _CONSTRAINTS_H

enum ConstrType{
	CT_ORTHO = 0,
	CT_PARALLEL
};

// Ограничение ортогональности 2 отрезков
class ConstrOrtho{
};
// Ограничение параллельности 2 отрезков
class ConstrParallel{
};
// Ограничение принадлежности точки отрезку
class ConstrPonL{
};

#endif