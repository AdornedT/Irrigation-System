typedef struct InfPlanta
{
	
	uint8_t umidade;
	float tempMax;
	float tempMin;
	
} InfPlanta;

////Nome das plantas. Fazer desta forma facilita adicionar plantas ao menu para o desenvolvedor.
#define Planta0 "Cuidado Automatico   "
#define Planta1 "Alecrim              "
#define Planta2 "Amor Perfeito        "
#define Planta3 "Arruda               "
#define Planta4 "Citronela            "
#define Planta5 "Cravina              "
#define Planta6 "Espada de Sao Jorge  "
#define Planta7 "Flor de mel          "
#define Planta8 "Ixora mini           "
#define Planta9 "Kalanchoe            "
#define Planta10 "Lavanda              "
#define Planta11 "Pimenta Cumari       "
#define Planta12 "Suculenta            "

extern void DrawSelecionarMenu(uint8_t, bool, tContext);
extern InfPlanta SelecionarPlanta(uint8_t);