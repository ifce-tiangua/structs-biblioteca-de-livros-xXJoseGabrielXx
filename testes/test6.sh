echo "Testando (6)..."
echo

# Teste de uso do malloc
if grep -E '^[^/]*\bstruct\b' ./main.c; then
  echo "Pass: O tipo estruturado foi usado no código"
else
  echo "Fail: O tipo estruturado não foi encontrado no código"
  exit 1
fi

echo
echo "Teste 6 realizado com sucesso"

exit 0
