        function generateRandomString(length) {
            const characters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789';
            let result = '';

            for (let i = 0; i < length; i++) {
                const randomIndex = Math.floor(Math.random() * characters.length);
                result += characters.charAt(randomIndex);
            }

            return result;
        }

        // Example usage: Generate a random string of length 10
        const randomString = generateRandomString(10);
        console.log(randomString); // Output will be a random string of length 10



//RANDOM NUMBER
            function getRandomNumber(min, max) {
                let step1 = max - min + 1;
                let step2 = Math.random() * step1;
                let result = Math.floor(step2) + min;

                return result;
            }

            function generateRandomNumber(min, max) {
        return Math.floor(Math.random() * (max - min + 1)) + min;
    }

        const broj1 = getRandomNumber(1, 100);
