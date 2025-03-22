/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.cristogamesserver;

import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.security.SecureRandom;
import java.util.Base64;

/**
 *
 * @author hanokme
 */
public class TokenGenerator {
    public static String generateToken() {
        try {
            // Crear un número aleatorio seguro
            SecureRandom secureRandom = new SecureRandom();
            byte[] randomBytes = new byte[16]; // 16 bytes = 128 bits
            secureRandom.nextBytes(randomBytes);
            
            // Aplicar SHA-1 al número aleatorio
            MessageDigest sha1 = MessageDigest.getInstance("SHA-1");
            byte[] hash = sha1.digest(randomBytes);
            
            // Codificar el hash en Base64 para obtener una representación en cadena
            return Base64.getUrlEncoder().withoutPadding().encodeToString(hash);
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException("Error al generar el token", e);
        }
    }
}
