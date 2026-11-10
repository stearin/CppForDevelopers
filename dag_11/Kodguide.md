# Kodguide dag 11

Mallar och STL-behållare. C++23 i hela bygget. Varje numrerad cpp-fil har egen main/körfil. Förutsäg före körning. Övningar.md finns i samma mapp; main.cpp är lösningsförslag till sista uppgiften efter eget försök.

## Exempel och förväntningar

| Fil | Delmoment | Prova eller förvänta |
|---|---|---|
| [01_function.cpp](01_function.cpp) | Funktionsmall | 7; 2.5; pear |
| [02_class.cpp](02_class.cpp) | Klassmall | 2 80; room |
| [03_vector.cpp](03_vector.cpp) | Sekvens/kapacitet | Size: 3; 20 85 50 |
| [03_array.cpp](03_array.cpp) | Fast sammanhängande sekvens | Size: 3; 10 25 30 |
| [03_list.cpp](03_list.cpp) | Länkad sekvens | 10 15 20 30 40; Size: 5 |
| [span.cpp](span.cpp) | Valbar icke-ägande vy | 60; 61; 62 |
| [04_map.cpp](04_map.cpp) | Ordnade grupper | 1: 2; 2: 1 |
| [05_unordered.cpp](05_unordered.cpp) | Hash-uppslag | Lookups: 2 1 |
| [06_invalidation.cpp](06_invalidation.cpp) | Giltig referens/indexfel | 11; Rejected index |
| [extra_20_concepts.cpp](extra_20_concepts.cpp) | Valbart typkrav | 7; 7 |
| [main.cpp](main.cpp) | Gruppering | 1: count=2 mean=50; 2: count=1 mean=40 |

## Bygg och kör

Hämta kursmaterialet från GitHub. Öppna terminalen i dag_11, där CMakeLists.txt ligger. Kommandona nedan körs från den mappen.

```sh
cmake -S . -B build -G Ninja
cmake --build build
./build/day11_01_function.exe
./build/day11.exe
```

På Linux/macOS saknas normalt .exe. Numrerade mål heter day11_ följt av filnamn utan .cpp. Bygg inte alla cpp-filer i ett g++-kommando eftersom de har varsin main. För ett mål:

```sh
cmake --build build --target day11_01_function
```

## Hjälptyper och giltighet

Collection.hpp definierar klassmallen. Measurement.hpp innehåller post, parser och Statistics; huvudövningen använder bara post/statistik. 06_invalidation.cpp läser aldrig ogiltig referens. Concepts är valbart efter grundmallarna.

## Behållare före span

Studera vector, array och list innan span. Vector och array lagrar elementen sammanhängande; list använder länkade noder. Span kan därför visa en rå array, std::array eller std::vector, men inte std::list. Span äger inte data och förlänger inte deras livstid. Reallokering av vector kan göra vyn ogiltig.

```sh
./build/day11_03_array.exe
./build/day11_03_list.exe
./build/day11_span.exe
```

## Gör egna övningar

Arbeta självständigt med Övningar.md. Delarnas lösningsprinciper och hänvisningar finns där. Visa gärna för en klasskamrat; egen kontroll och anteckningar fungerar om ingen är tillgänglig.

## Begrepp och syntax i exemplen

Förklaringarna används tillsammans med genomgången. Extraavsnittens begrepp behövs bara om du väljer dessa exempel.

### template<typename T>

template inleder en mall. typename anger att T är en typparameter; T är ett valfritt namn. Collection<int> väljer int som denna typ. En instansiering skapar den version av mallen som behövs för typen.

### std::size_t

En osignerad heltalstyp som bland annat används för behållarstorlekar och index. Den kan inte representera negativa index.

### Iterator och invalidation

En iterator betecknar en position i en sekvens. Invalidation betyder att en operation gör en tidigare iterator eller referens ogiltig; den får då inte användas för åtkomst.

### std::span<const int>

En icke-ägande vy med längd över sammanhängande int-element. const förbjuder ändring av elementen genom vyn. Den underliggande lagringen måste leva längre än användningen av vyn.

### std::integral (extra)

Ett namngivet typkrav, ett concept, som accepterar heltalstyper. template<std::integral T> begränsar vilka typer som får användas som T.

