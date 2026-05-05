g++ -O3 -o analizador ordenamientos.cppAquí tienes una versión del `README.md` con un enfoque más técnico y detallado, ideal para un perfil de Ingeniería de Sistemas. Se han integrado las nuevas capturas de pantalla y se ha estructurado para resaltar la metodología de pruebas.

---

# 🚀 Laboratorio de Análisis Algorítmico (C++)

Este repositorio contiene una herramienta de ingeniería de software diseñada para el estudio empírico de la complejidad computacional. El sistema evalúa el rendimiento de diversos métodos de ordenamiento mediante **micro-benchmarking**, permitiendo observar la diferencia real entre las complejidades teóricas y el tiempo de ejecución en hardware moderno.

---

## 👨‍💻 Información Académica
*   **Institución:** Universidad Nacional del Altiplano (UNAP)
*   **Carrera:** Ingeniería de Sistemas
*   **Cátedra:** Programación de Sistemas / Algoritmos
*   **Docente:** Profesora Mayenka Fernandez Chambi

---

## 🛠️ Metodología de Medición

Para garantizar que los datos obtenidos sean estadísticamente significativos, el programa implementa:

*   **Reloj Monotónico:** Se utiliza `std::chrono::steady_clock` para obtener una resolución en nanosegundos, evitando saltos temporales del sistema.
*   **Promediado por Ensayos:** Cada algoritmo se somete a **1000 iteraciones** (`ENSAYOS = 1000`). Esto permite diluir el impacto de las interrupciones del kernel y el context-switching del CPU.
*   **Eliminación de Sesgo de Compilador:** Se incluye una fase de "calentamiento" para asegurar que las optimizaciones de caché y predicción de saltos del procesador estén activas antes de la medición.
*   **Contadores de Pasos:** Registro de operaciones críticas para validar las cotas superiores $O(g(n))$ de cada método.

---

## 📸 Evidencias de Pruebas

El sistema ha sido validado mediante múltiples escenarios de carga para confirmar la consistencia de los tiempos de respuesta.

### Prueba 1: Validación de Datos de Entrada
Se observa la generación aleatoria de elementos y la configuración inicial de los parámetros de rango para el vector base.

![Configuración Inicial](Captura%20de%20pantalla%202026-05-05%20185112.png)

### Prueba 2: Reporte Final de Benchmarking
El software clasifica automáticamente los métodos basándose en el **Tiempo Promedio**, demostrando la superioridad de los algoritmos de división y conquista en arreglos de gran escala.

![Reporte de Rendimiento](Captura%20de%20pantalla%202026-05-05%20185222.png)

---

## 📊 Comparativa de Algoritmos

| Método | Clasificación | Complejidad Teórica | Estabilidad |
| :--- | :--- | :--- | :--- |
| **Quick Sort** | Divide y Vencerás | $O(n \log n)$ | Inestable |
| **Merge Sort** | Divide y Vencerás | $O(n \log n)$ | Estable |
| **Insertion Sort** | Inserción | $O(n^2)$ | Estable |
| **Selection Sort** | Selección | $O(n^2)$ | Inestable |
| **Burbuja** | Intercambio | $O(n^2)$ | Estable |

---

## ⚙️ Guía de Compilación y Uso

Para replicar estas pruebas en su entorno local, siga estos pasos:

1.  **Asegurar Requisitos:** Tener instalado un compilador que soporte el estándar C++11 (como G++ o Clang).
2.  **Compilación Técnica:**
    ```bash
    g++ -O3 -o analizador ordenamientos.cpp
    ```
    *(Nota: Se recomienda el flag `-O3` para habilitar optimizaciones de alto nivel).*
3.  **Ejecución:**
    Aquí tienes una versión del `README.md` con un enfoque más técnico y detallado, ideal para un perfil de Ingeniería de Sistemas. Se han integrado las nuevas capturas de pantalla y se ha estructurado para resaltar la metodología de pruebas.

---

# 🚀 Laboratorio de Análisis Algorítmico (C++)

Este repositorio contiene una herramienta de ingeniería de software diseñada para el estudio empírico de la complejidad computacional. El sistema evalúa el rendimiento de diversos métodos de ordenamiento mediante **micro-benchmarking**, permitiendo observar la diferencia real entre las complejidades teóricas y el tiempo de ejecución en hardware moderno.

---

## 👨‍💻 Información Académica
*   **Institución:** Universidad Nacional del Altiplano (UNAP)
*   **Carrera:** Ingeniería de Sistemas
*   **Cátedra:** Programación de Sistemas / Algoritmos
*   **Docente:** Profesora Mayenka Fernandez Chambi

---

## 🛠️ Metodología de Medición

Para garantizar que los datos obtenidos sean estadísticamente significativos, el programa implementa:

*   **Reloj Monotónico:** Se utiliza `std::chrono::steady_clock` para obtener una resolución en nanosegundos, evitando saltos temporales del sistema.
*   **Promediado por Ensayos:** Cada algoritmo se somete a **1000 iteraciones** (`ENSAYOS = 1000`). Esto permite diluir el impacto de las interrupciones del kernel y el context-switching del CPU.
*   **Eliminación de Sesgo de Compilador:** Se incluye una fase de "calentamiento" para asegurar que las optimizaciones de caché y predicción de saltos del procesador estén activas antes de la medición.
*   **Contadores de Pasos:** Registro de operaciones críticas para validar las cotas superiores $O(g(n))$ de cada método.

---

## 📸 Evidencias de Pruebas

El sistema ha sido validado mediante múltiples escenarios de carga para confirmar la consistencia de los tiempos de respuesta.

### Prueba 1: Validación de Datos de Entrada
Se observa la generación aleatoria de elementos y la configuración inicial de los parámetros de rango para el vector base.

![Configuración Inicial](Captura%20de%20pantalla%202026-05-05%20185112.png)

### Prueba 2: Reporte Final de Benchmarking
El software clasifica automáticamente los métodos basándose en el **Tiempo Promedio**, demostrando la superioridad de los algoritmos de división y conquista en arreglos de gran escala.

![Reporte de Rendimiento](Captura%20de%20pantalla%202026-05-05%20185222.png)

---

## 📊 Comparativa de Algoritmos

| Método | Clasificación | Complejidad Teórica | Estabilidad |
| :--- | :--- | :--- | :--- |
| **Quick Sort** | Divide y Vencerás | $O(n \log n)$ | Inestable |
| **Merge Sort** | Divide y Vencerás | $O(n \log n)$ | Estable |
| **Insertion Sort** | Inserción | $O(n^2)$ | Estable |
| **Selection Sort** | Selección | $O(n^2)$ | Inestable |
| **Burbuja** | Intercambio | $O(n^2)$ | Estable |

---

## ⚙️ Guía de Compilación y Uso

Para replicar estas pruebas en su entorno local, siga estos pasos:

1.  **Asegurar Requisitos:** Tener instalado un compilador que soporte el estándar C++11 (como G++ o Clang).
2.  **Compilación Técnica:**
    ```bash
    g++ -O3 -o analizador ordenamientos.cpp
    ```
    *(Nota: Se recomienda el flag `-O3` para habilitar optimizaciones de alto nivel).*
3.  **Ejecución:**
    ```bash
    ./analizador
    ```

> [!TIP]
> Al realizar las pruebas, se recomienda no tener procesos pesados abiertos paraAquí tienes una versión del `README.md` con un enfoque más técnico y detallado, ideal para un perfil de Ingeniería de Sistemas. Se han integrado las nuevas capturas de pantalla y se ha estructurado para resaltar la metodología de pruebas.

---

# 🚀 Laboratorio de Análisis Algorítmico (C++)

Este repositorio contiene una herramienta de ingeniería de software diseñada para el estudio empírico de la complejidad computacional. El sistema evalúa el rendimiento de diversos métodos de ordenamiento mediante **micro-benchmarking**, permitiendo observar la diferencia real entre las complejidades teóricas y el tiempo de ejecución en hardware moderno.

---

## 👨‍💻 Información Académica
*   **Institución:** Universidad Nacional del Altiplano (UNAP)
*   **Carrera:** Ingeniería de Sistemas
*   **Cátedra:** Programación de Sistemas / Algoritmos
*   **Docente:** Profesora Mayenka Fernandez Chambi

---

## 🛠️ Metodología de Medición

Para garantizar que los datos obtenidos sean estadísticamente significativos, el programa implementa:

*   **Reloj Monotónico:** Se utiliza `std::chrono::steady_clock` para obtener una resolución en nanosegundos, evitando saltos temporales del sistema.
*   **Promediado por Ensayos:** Cada algoritmo se somete a **1000 iteraciones** (`ENSAYOS = 1000`). Esto permite diluir el impacto de las interrupciones del kernel y el context-switching del CPU.
*   **Eliminación de Sesgo de Compilador:** Se incluye una fase de "calentamiento" para asegurar que las optimizaciones de caché y predicción de saltos del procesador estén activas antes de la medición.
*   **Contadores de Pasos:** Registro de operaciones críticas para validar las cotas superiores $O(g(n))$ de cada método.

---

## 📸 Evidencias de Pruebas

El sistema ha sido validado mediante múltiples escenarios de carga para confirmar la consistencia de los tiempos de respuesta.

### Prueba 1: Validación de Datos de Entrada
Se observa la generación aleatoria de elementos y la configuración inicial de los parámetros de rango para el vector base.

![Configuración Inicial](Captura%20de%20pantalla%202026-05-05%20185112.png)

### Prueba 2: Reporte Final de Benchmarking
El software clasifica automáticamente los métodos basándose en el **Tiempo Promedio**, demostrando la superioridad de los algoritmos de división y conquista en arreglos de gran escala.

![Reporte de Rendimiento](Captura%20de%20pantalla%202026-05-05%20185222.png)

---

## 📊 Comparativa de Algoritmos

| Método | Clasificación | Complejidad Teórica | Estabilidad |
| :--- | :--- | :--- | :--- |
| **Quick Sort** | Divide y Vencerás | $O(n \log n)$ | Inestable |
| **Merge Sort** | Divide y Vencerás | $O(n \log n)$ | Estable |
| **Insertion Sort** | Inserción | $O(n^2)$ | Estable |
| **Selection Sort** | Selección | $O(n^2)$ | Inestable |
| **Burbuja** | Intercambio | $O(n^2)$ | Estable |

---

## ⚙️ Guía de Compilación y Uso

Para replicar estas pruebas en su entorno local, siga estos pasos:

1.  **Asegurar Requisitos:** Tener instalado un compilador que soporte el estándar C++11 (como G++ o Clang).
2.  **Compilación Técnica:**
    ```bash
    g++ -O3 -o analizador ordenamientos.cpp
    ```
    *(Nota: Se recomienda el flag `-O3` para habilitar optimizaciones de alto nivel).*
3.  **Ejecución:**
    ```bash
    ./analizador
    ```

> [!TIP]
> Al realizar las pruebas, se recomienda no tener procesos pesados abiertos para que el `steady_clock` capture el tiempo de CPU dedicado exclusivamente al proceso de ordenamiento.
