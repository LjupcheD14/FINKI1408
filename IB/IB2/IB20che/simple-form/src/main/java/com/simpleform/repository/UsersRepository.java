package com.simpleform.repository;

import com.simpleform.model.UsersModel;
import org.apache.catalina.User;
import org.springframework.data.jpa.repository.JpaRepository;

import java.util.Optional;

public interface UsersRepository extends JpaRepository<UsersModel, Integer> {
    Optional<UsersModel> findByLoginAndPassword(String login, String password);


    Optional<UsersModel> findFirstByLogin(String login);
}
