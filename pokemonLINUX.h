//pokemonLINUX.h
//depends on stdint.h
//type defs for (first gen)pokemon related data
//2018 Zack Mitchell Klaric.

typedef struct pokemon_s  {

  uint8_t    Index     ;  // Index number of the Species
  uint16_t   CurHp     ;  // Current HP
  uint8_t    FLevel    ;  // (false) Level
  uint8_t    Status    ;  // Status Condition 
  uint8_t    Type1     ;  // Type 1
  uint8_t    Type2     ;  // Type 2
  uint8_t    Catch     ;  // Catch rate/Held item
  uint8_t    Index1    ;  // Index number of move 1
  uint8_t    Index2    ;  // Index number of move 2
  uint8_t    Index3    ;  // Index number of move 3
  uint8_t    Index4    ;  // Index number of move 4
  uint16_t   Trainer   ;  // Original Trainer ID number
  uint8_t    Exp[3]    ;  // Experiance Points (3bytes)
  uint16_t   HpEV      ;  // Hp      Effort Value data
  uint16_t   AttackEV  ;  // Attack  Effort Value data 
  uint16_t   DefenseEV ;  // Defense Effort Value data
  uint16_t   SpeedEV   ;  // Speed   Effort Value data
  uint16_t   SpecialEV ;  // Special Effort Value data
  uint16_t   IV        ;  // Individual value (determinant value) data
  uint8_t    PP1       ;  // Move 1's PP value
  uint8_t    PP2       ;  // Move 2's PP value
  uint8_t    PP3       ;  // Move 3's PP value
  uint8_t    PP4       ;  // Move 4's PP value
  uint8_t    Level     ;  // Pokemon's level
  uint16_t   MaxHp     ;  // Maximum Hp
  uint16_t   Attack    ;  // Attack
  uint16_t   Defense   ;  // Defense
  uint16_t   Speed     ;  // Speed 
  uint16_t   Special   ;  // Special
  
  }__attribute__ ((packed)) pokemon_t;  //sizeof()  says 48 bytes???? write only 44 ,fixed with (pack)
  

  
