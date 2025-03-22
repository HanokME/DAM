/**
 * @file HibernateUtil.java
 * @brief Programación de la clase HibernateUtil perteneciente al modelo del programa.
 * @version 1.1
 * @date 26/02/2025
 * @author Alexmrdgz
 * @copyright Copyright (c) 2025
 */

package modelo;

import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;
import org.hibernate.service.ServiceRegistry;
import org.hibernate.boot.registry.StandardServiceRegistryBuilder;

public class HibernateUtil {
    
    //Atributo
    private static SessionFactory sessionFactory = null;

    //Crea la fábrica de sesiones si no está inicializada
    public static void buildSessionFactory() {
        if (sessionFactory == null) {
            Configuration configuration = new Configuration();
            configuration.configure();
            
            //Registra las clases mapeadas
            configuration.addAnnotatedClass(Genero.class);
            configuration.addAnnotatedClass(Juego.class);
            configuration.addAnnotatedClass(Perfil.class);
            configuration.addAnnotatedClass(Resenia.class);
            configuration.addAnnotatedClass(Usuario.class);
            
            ServiceRegistry serviceRegistry = new StandardServiceRegistryBuilder().applySettings(configuration.getProperties()).build();
            sessionFactory = configuration.buildSessionFactory(serviceRegistry);
        }
    }
    
    //Devuelve la fábrica de sesiones
    public static SessionFactory getSessionFactory() {
        if (sessionFactory == null) {
            buildSessionFactory();
        }
        return sessionFactory;
    }
    
    //Devuelve una nueva sesión por cada llamada (para uso en múltiples hebras)
    public static Session getCurrentSession() {
        return getSessionFactory().openSession();
    }
    
    //Cierra Hibernate correctamente
    public static void closeSessionFactory() {
        if (sessionFactory != null) {
            sessionFactory.close();
        }
    }
}

