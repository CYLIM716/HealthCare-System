# Project Features & Technical Implementations (Array Engine) ⚡

This program acts as the core memory-contiguous processing framework for the MetroHealth System Hospital Patient Management analytics suite. It is written entirely in native **C++** without utilizing any built-in STL containers (such as `<vector>` or `<list>`) to strictly evaluate fundamental memory performance.

### 🧱 Custom Memory & Array Engine
*   **Static/Dynamic Array Buffers:** Implements independent, custom-engineered array allocation structures to hold patient profiles across three medical facilities.
*   **Contiguous Memory Layout:** Leverages cache-friendly sequential storage systems to achieve lightning-fast direct indexing and iteration boundaries during analysis.
*   **Zero-STL Data Streams:** Manages raw data elements reading directly from hospital `.csv` datasets using self-created array resizing mechanics.

### 📊 Health Analytics & Data Manipulation
*   **Demographic Segmentation:** Categorizes array elements dynamically into 5 key age groups (Pediatrics up to Geriatrics).
*   **Medical Billing Metrics:** Aggregates cumulative billing insights per cell instance using the core formula: `Length of Stay × Base Rate × Visits Per Year`.
*   **Consolidated Text Tables:** Compiles analytical insights and displays sorted datasets inside formatted, fixed-width ASCII terminal consoles.

### 🔬 Experimental Array Sorting & Searching 
*   **Sequential Sorting Pipeline:** Implements native [insert your algorithm, e.g., Bubble/Selection/Insertion Sort] directly across the array boundary to organize data by Age, Stay Duration, or Total Cost.
*   **Unsorted vs. Sorted Search:** Executes conditional searching (Linear/Binary) to parse arrays for age brackets, urgent care filters, or high-stay thresholds.
*   **Asymptotic Profiling Tooling:** Embeds performance log micro-scripts recording CPU runtime ticks and storage usage metrics for comparative structure profiling.
