echo "Testando (5)..."
echo

# Teste de uso do malloc
if grep -E '^[^/]*\bfree\b' ./main.c; then
  echo "Pass: A função free foi usada no código"
else
  echo "Fail: A função free não foi encontrada no código"
  exit 1
fi

echo
echo "Teste 5 realizado com sucesso"

exit 0
