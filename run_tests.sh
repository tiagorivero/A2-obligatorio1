#!/bin/bash
# Fragmento generado con Claude (Anthropic): script para compilar cada ejercicio
# y correr los casos de tests/ejercicioX (X.in.txt -> se compara con X.out.txt).
#
# Uso (desde la raíz del proyecto, donde están los ejercicioX.cpp):
#   ./run_tests.sh          -> corre los ejercicios 1 a 5
#   ./run_tests.sh 2 4      -> corre solo los ejercicios 2 y 4
#
# Las salidas obtenidas quedan en salidas/ejercicioX/ para poder revisarlas.

if [ $# -eq 0 ]; then
  EJERCICIOS=(1 2 3 4 5)
else
  EJERCICIOS=("$@")
fi

VERDE="\033[0;32m"; ROJO="\033[0;31m"; AMARILLO="\033[0;33m"; NC="\033[0m"
TIMEFORMAT=%R   # 'time' de bash imprime solo los segundos reales

total=0
total_ok=0

for X in "${EJERCICIOS[@]}"; do
  src="ejercicio$X.cpp"
  bin="./ejercicio$X"
  dir_tests="tests/ejercicio$X"
  dir_salidas="salidas/ejercicio$X"

  echo "=============================="
  echo " Ejercicio $X"
  echo "=============================="

  if [ ! -f "$src" ]; then
    echo -e "${AMARILLO}No existe $src, se saltea.${NC}"
    continue
  fi

  # Misma compilación que indica la letra
  if ! g++ -o "ejercicio$X" "$src" -std=c++11; then
    echo -e "${ROJO}Error de compilación en $src${NC}"
    continue
  fi

  mkdir -p "$dir_salidas"
  ok=0; cant=0

  for entrada in "$dir_tests"/*.in.txt; do
    [ -e "$entrada" ] || { echo -e "${AMARILLO}No hay casos en $dir_tests${NC}"; break; }

    nombre=$(basename "$entrada" .in.txt)
    esperada="$dir_tests/$nombre.out.txt"
    obtenida="$dir_salidas/$nombre.out.txt"
    cant=$((cant + 1))

    if [ ! -f "$esperada" ]; then
      echo -e "${AMARILLO}[ ?? ] $nombre (falta $nombre.out.txt)${NC}"
      continue
    fi

    # Ejecuta midiendo el tiempo; el stderr del programa se descarta
    tiempo=$( { time "$bin" < "$entrada" > "$obtenida" 2>/dev/null; } 2>&1 )
    codigo=$?

    # -b ignora diferencias de espacios al final de línea (y \r de Windows),
    # -B ignora líneas vacías extra
    if diff -b -B "$esperada" "$obtenida" > /dev/null; then
      echo -e "${VERDE}[ OK ]${NC} $nombre (${tiempo}s)"
      ok=$((ok + 1))
    else
      echo -e "${ROJO}[FAIL]${NC} $nombre (${tiempo}s)"
      echo "       primeras diferencias (< esperada | > obtenida):"
      diff -b -B "$esperada" "$obtenida" | head -n 6 | sed 's/^/       /'
    fi
  done

  echo "Ejercicio $X: $ok/$cant casos correctos"
  total=$((total + cant))
  total_ok=$((total_ok + ok))
done

echo "=============================="
echo " TOTAL: $total_ok/$total casos correctos"
echo "=============================="