#define DESC_LEN 30

typedef struct
{
    int id;
    char description[DESC_LEN];

} Sector;


/** \brief Load some sector data to testing
 *
 * \param list Sector* Pointer to array of sectors
 * \param len int Array length
 * \param id int* Sector ID to load
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int hardCodeSectors(Sector* list, int len, int* id);


/** \brief Find a Sector by ID
 *
 * \param list Sector* Pointer to array of sectors
 * \param len int Array length
 * \param id int Sector ID to search
 *
 * \return int (-1) if [Invalid length or NULL pointer received or sector not found] or sector index position
 *
 */
int findSectorById(Sector* list, int len, int id);


/** \brief Print the content of sector
 *
 * \param aSector Sector* Pointer to one sector
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int printASector(Sector* aSector);


/** \brief Print the content of sectors array
 *
 * \param list Sector* Pointer to array of sectors
 * \param len int Array length
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int printSectors(Sector* list, int len);

