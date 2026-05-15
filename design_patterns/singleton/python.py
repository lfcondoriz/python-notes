# ============================================================================
# FORMA PYTHÓNICA: Usar un módulo como Singleton
# ============================================================================
# 
# En Python, los módulos se importan solo UNA VEZ y se cachean en sys.modules.
# Esto hace que un módulo sea automáticamente singleton sin necesidad de 
# implementar patrones complejos como en otros lenguajes.
#
# VENTAJAS sobre implementar Singleton con clases:
# - Más simple y legible
# - Sigue la filosofía de Python (simple is better than complex)
# - Thread-safe por defecto
# - Rendimiento mejor
# ============================================================================

# Archivo: _config.py (módulo singleton)
# Se carga UNA sola vez al importar
_config = {}
_is_loaded = False

def _load():
    """Carga la configuración una sola vez."""
    global _config, _is_loaded
    if _is_loaded:
        return
    
    file_path = "design_patterns/singleton/config.txt"
    try:
        with open(file_path, "r") as f:
            for line in f:
                if line.strip():
                    key, value = line.strip().split("=")
                    _config[key] = value
        _is_loaded = True
        print(f"[CONFIG] Cargadas {len(_config)} configuraciones (1 sola vez)")
    except FileNotFoundError:
        print(f"[ERROR] Archivo {file_path} no encontrado")

# Se ejecuta al importar el módulo (una sola vez)
_load()

def get(key, default=None):
    """Obtiene una configuración."""
    return _config.get(key, default)

def get_all():
    """Obtiene todas las configuraciones."""
    return _config.copy()


# ============================================================================
# DEMOSTRACIÓN
# ============================================================================
if __name__ == "__main__":
    print("\n=== Primer acceso ===")
    from __main__ import get
    print(f"db_host: {get('db_host')}")
    print(f"db_user: {get('db_user')}")

    print("\n=== Segundo acceso (el módulo NO se recarga) ===")
    print(f"app_name: {get('app_name')}")
    print(f"app_version: {get('app_version')}")

    print("\n=== Verificación ===")
    import sys
    print(f"Módulo en sys.modules: {'__main__' in sys.modules}")
    print(f"Este es el mismo módulo siempre: Sí (los módulos no se recargan)")